#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include "node.h"
#include "table.h"
#include "treeIdx.h"
#include "hashIdx.h"
//0508
#include "cret_idx.h"
#define SELECT_LOG "select_log.txt"

#include "select_destroy.h"

#define MAX_STMT_NUM_SUPPORT 20
#define MAX_IMPORT_FILE_NAME_LENGTH 100

typedef bool (*sql_cmp_two_tuple)(tuple_t *new, tuple_t *exist, attr_node_header_t *attr);
typedef int (*sql_idx_cb)(table_node_t *tbl, char *attrName, var_node_t *v, cmp_type_e cmptype, tuple_t *inTpl, tuple_t **outTpl);
typedef void (*stmt_dstry_func)(stmt_node_t*);
static table_node_t *table_list[MAX_TABLE_ENTRY] = { NULL };
static db_db_t dbms;
//static bp_db_t db_tree;

stmt_dstry_func *stmt_dstry;
static char intMAX[64];
static char intMIN[64];
sql_idx_cb sql_index_cb[5];

bool sql_is_dup_tuple_chk(table_node_t *self, tuple_t *new_tuple);
static tuple_t *sql_tuple_create_and_init(void);
bool sql_insr_check_col_list_valid(table_node_t *self, col_node_t *colNodeList);

attr_node_header_t *sql_insr_find_attr_in_table(table_node_t *tbl, char *attrName);
bool sql_sel_collect_table(sel_rec_t *rec, select_table_node_t *tableList);
char *sql_sel_find_tbl_name(sel_rec_t *rec, char *pfx);
bool sql_sel_collect_attr(sel_rec_t *rec, select_col_node_t* colList);
void printAttrList(sel_rec_t *rec);
int sql_set_table_idx_tree(bp_db_t *db, table_node_t *tbl, col_node_t *col_list);
int sql_idx_get_tuple(bp_db_t *db, table_node_t *tbl, var_node_t *v, tuple_t **tupleOut);
int sql_idx_get_tuple_range(bp_db_t *db, table_node_t *tbl, var_node_t *start, var_node_t *end, tuple_t **tupleOut);
//0508
int sql_hash_idx_get_tuple(table_node_t *table, char * attrName, var_node_t* hashKey, tuple_t **tupleOut);
int sql_set_table_idx_hash(table_node_t *tbl, col_node_t *col_list);
//0508
bool sql_create_idx_stmt_handle(cret_idx_stmt_t *cretIdxStmt);
int sql_sel_cond_handle(sel_rec_t *rec, table_node_t *tbl, tuple_t *inTpl, tuple_t **outTpl, cmp_eval_t *cmpEval);
static table_node_t *sql_cret_tbl_table_create_and_init(char *name);
cmp_eval_t *sql_get_cmp_from_table(sel_rec_t *rec, int idx);
void sql_save_qual_tuple(sel_rec_t *rec, tuple_cnn_t *tplCnn);

int sql_qual_tuple_list(char *attrName, var_node_t *cmp, cmp_type_e cmpType, tuple_t *inTpl, tuple_t **outTpl, tuple_t **tail)
{
    tuple_t *t_start = inTpl;
    tuple_t *tupleToOut, *tailToOut;
    tuple_t **tupleTmp = &tupleToOut;
    bool result = false;

    while (t_start) 
    {
        attr_node_t *attrNd = t_start->find_attr_vals(t_start, attrName);
        result = false;
        if (attrNd) 
        {
            if (attrNd->header->data_type == cmp->type) 
            {
                switch (cmpType) 
                {
                    case CMP_TYPE_LESS:
                        if (cmp->type == DATA_TYPE_INT)
                            result =  (attrNd->value->int_value < cmp->int_value);
                        else
                            printf("not allowed type for cmp operator: LESS\n");
                        break;
                    case CMP_TYPE_GREATER:
                        if (cmp->type == DATA_TYPE_INT)
                            result =  (attrNd->value->int_value > cmp->int_value);
                        else
                            printf("not allowed type for cmp operator: GREATER\n");
                        break;
                    case CMP_TYPE_EQUAL:
                        if (cmp->type == DATA_TYPE_INT)
                            result =  (attrNd->value->int_value == cmp->int_value);
                        else if (cmp->type == DATA_TYPE_VARCHAR)
                            result = (strcmp(attrNd->value->varchar_value, cmp->varchar_value) == 0);
                        else
                            printf("not allowed type for cmp operator: EQUAL\n");
                        break;
                    case CMP_TYPE_NOTEQUAL:
                        if (cmp->type == DATA_TYPE_INT)
                            result =  (attrNd->value->int_value != cmp->int_value);
                        else if (cmp->type == DATA_TYPE_VARCHAR)
                            result = (strcmp(attrNd->value->varchar_value, cmp->varchar_value) != 0);
                        else
                            printf("not allowed type for cmp operator: EQUAL\n");
                        break;
                    default:
                        printf("unexpected cmp type\n");
                    break;
                }
            }          
        }
        if (result) {
            *tupleTmp = t_start;
            tailToOut = t_start;
            t_start = t_start->next;
            tupleTmp = &((*tupleTmp)->next);
            *tupleTmp = NULL;
        } else {
            t_start = t_start->next;
        }
    }
    *outTpl = tupleToOut;
    *tail = tailToOut;
    return 0;
}


int sql_idx_full_scan_cb(table_node_t *tbl, char *attrName, var_node_t *cmp, cmp_type_e cmptype, tuple_t *inTpl, tuple_t **outTpl)
{
    tuple_t *t_start;
    tuple_t *tupleToOut;
    tuple_t **tupleTmp = &tupleToOut;
    tuple_t *tail;
    bool result = false;
    if (inTpl) {
        t_start = inTpl;
        sql_qual_tuple_list(attrName, cmp, cmptype, t_start, outTpl, &tail);
    }
    else 
    {
        uint32_t tupleNum;
        uint16_t offset, pageOffset, pageNum;
        char *page; 
        int i, ret;
        tuple_t *headToOut, *tailToOut, *out_tuple;
        tuple_t *tuple, *tuplelist;
        tuple_t **tupleTmp = &tuplelist;
        pageNum = ntohl(*(uint32_t *)(tbl->pageTable[0].page + DB_PAGE_HEADER_SIZE));
        tupleNum = 0;
        for (i = 1; i < pageNum; i++) 
        {
            offset = DB_PAGE_HEADER_SIZE;
            if (tbl->pageTable[i].valid_bit == 0 )
            {
                ret = db__table_info_page_fault_hdl(tbl, i, (char **)&page);
                if (ret!=BP_OK)
                    printf("error\n");
                else 
                    tbl->pageTable[i].page = page;
            } else {
                page = tbl->pageTable[i].page;    
            }
            pageOffset = *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_OFFSET);
            while (offset < pageOffset) {
                tuple = sql_tuple_create_and_init();
                tuple->pageId = i;
                tuple->offset = offset;
                printf("(%d, %d)\n", i, offset);
                db__page_tuple_info_unpacked(tbl, tuple, &offset, page);
                //tbl->add_tuple(tbl, tuple);
                *tupleTmp = tuple;
                tupleTmp = &((*tupleTmp)->next);
                tupleNum++;
            }
            /*
            if (!headToOut){
                headToOut = out_tuple; 
            } else {
                tailToOut->next = out_tuple;    
            }*/
            //tupleTmp = &tuplelist;
            //tailToOut = tail;
        }
        sql_qual_tuple_list(attrName, cmp, cmptype, tuplelist, &out_tuple, &tail);
        *outTpl = out_tuple;
    }
    return 0;   
}

int sql_idx_hash_cb(table_node_t *tbl, char *attrName, var_node_t *v, cmp_type_e cmpType, tuple_t *inTpl, tuple_t **outTpl)
{
    printf("Entering hash call back func.\n");
    if (cmpType == CMP_TYPE_EQUAL){
        printf("    Start get tuple\n");
        sql_hash_idx_get_tuple(tbl, attrName, v, outTpl);
    } 
}

int sql_idx_tree_cb(table_node_t *tbl, char *attrName, var_node_t *v, cmp_type_e cmpType, tuple_t *inTpl, tuple_t **outTpl)
{
    char fileName[128];
    sprintf(fileName, "%s_%s_tree.idx", tbl->name, attrName);
    bp_db_t db_tree;
    var_node_t _interVar;
    int ret;
    ret = db__tree_idx_create(&db_tree, fileName);
    db__tree_set_num_compare_cb(&db_tree);
    
    if (ret != BP_OK) {
        printf("can not get tree idx\n");
        return ret;
    }
    _interVar.type = v->type;
    if ( v->type == DATA_TYPE_INT ) {
        if (cmpType == CMP_TYPE_GREATER) {
            _interVar.int_value = INT_MAX;
            v->int_value++;
            sql_idx_get_tuple_range(&db_tree, tbl, v, &_interVar, outTpl);
        }
        else { 
            _interVar.int_value = INT_MIN;
            v->int_value--;
            sql_idx_get_tuple_range(&db_tree, tbl, &_interVar, v, outTpl);
        
        }
    }
    //TODO:else v->type = DATA_TYPE_VARCHAR;
    return 0;
}

int sql_sel_merge_tuple_for_or_cond(sel_rec_t *rec, table_node_t *tbl, tuple_t *list1, tuple_t *list2, tuple_t **tupleOut)
{
    tuple_t *tupleBackup = tbl->tuple_list_head;
    tuple_t *t2 = list2;
    table_node_t *tmpTbl = sql_cret_tbl_table_create_and_init("tmp");
    tbl->tuple_list_head = list1;
    
    while (t2) {
        if (!tbl->chk_duplc(tbl, t2)) // no duplicated
            tmpTbl->add_tuple(tmpTbl,t2);
        t2 = t2->next;
    }
    if ( tmpTbl->tuple_list_head) {
        tmpTbl->tuple_list_tail->next = list1;
        *tupleOut = tmpTbl->tuple_list_head;
    } else {
        *tupleOut = list1;
    }
    tbl->tuple_list_head = tupleBackup;
    free(tmpTbl);
    return 0;
}

int sql_sel_merge_tuple_for_and_cond(sel_rec_t *rec, table_node_t *tbl, tuple_t *list1, tuple_t *list2, tuple_t **tupleOut)
{
    tuple_t *tupleBackup = tbl->tuple_list_head;
    tuple_t *t2 = list2;
    table_node_t *tmpTbl = sql_cret_tbl_table_create_and_init("tmp");
    tbl->tuple_list_head = list1;
    
    while (t2) {
        if (tbl->chk_duplc(tbl, t2)) // no duplicated
            tmpTbl->add_tuple(tmpTbl,t2);
        t2 = t2->next;
    }
    *tupleOut = tmpTbl->tuple_list_head;

    tbl->tuple_list_head = tupleBackup;
    free(tmpTbl);
    return 0;
}

int sql_sel_table_qual_tuple(sel_rec_t *rec, table_node_t *tbl, int tblIdx, tuple_t **tupleOut)
{
    int condNum = rec->cmpTblNum[tblIdx];
    tuple_t *tupleToOut = NULL;
    cmp_eval_t *cmpEval = sql_get_cmp_from_table(rec, tblIdx);
    
    if (condNum == 2) 
    {
        // cmpTblNum[0] =2 || cmpTblNum[1] = 2 =>  pack tupleCnn directly
        tuple_t *list1, *list2;
        if (rec->lgcOp == LGC_TYPE_OR) {
            sql_sel_cond_handle(rec, tbl, NULL, &list1, cmpEval);
            sql_sel_cond_handle(rec, tbl, NULL, &list2, cmpEval->next);
            sql_sel_merge_tuple_for_or_cond(rec, tbl, list1, list2, &tupleToOut);// rec for count 
        }
        else if (rec->lgcOp == LGC_TYPE_AND) {
            bool isScan;
            sql_sel_cond_handle(rec, tbl, NULL, &list1, cmpEval);
            sql_sel_cond_handle(rec, tbl, list1, &list2, cmpEval->next);
            tupleToOut = list2;
        }
    
    } 
    else if (condNum == 1) 
    {
        tuple_t *list;
        sql_sel_cond_handle(rec, tbl, NULL, &list, cmpEval);
        tupleToOut = list;
        if (rec->cmpJoin) {
            rec->outerIdx = tblIdx;
            rec->outerTuple = tupleToOut;
        }
    } 
    else if (condNum == 0) 
    {
        if (tbl) tupleToOut = tbl->tuple_list_head;
    } 
    else 
    {
        printf("condNum is not correct\n");
    }
    *tupleOut = tupleToOut;
    return 0;
}


int sql_sel_cond_handle(sel_rec_t *rec, table_node_t *tbl, tuple_t *inTpl, tuple_t **outTpl, cmp_eval_t *cmpEval)
{
    
    char *attrName; 
    var_node_t *v;
    cmp_type_e cmpType;
    idx_cb_type_e cbType;
    attr_node_header_t *attrHd;
    attrName = cmpEval->cmp->left->varchar_value;
    attrHd = tbl->find_attr(tbl, attrName);
    v = cmpEval->cmp->right;
    if (inTpl || ( (attrHd->col_attr&ATTR_PRIKEY) == 0 && cmpEval->cmp->type != CMP_TYPE_EQUAL))
    {
        cbType = IDX_CB_TYPE_SCAN;
    }
    else
    {
        cbType = (idx_cb_type_e)cmpEval->cmp->type;
    }
    sql_index_cb[cbType](tbl, attrName, v, cmpEval->cmp->type, inTpl, outTpl);
    
    return BP_OK;
}

int sql_sel_qual_start(sel_rec_t *rec)
{
    tuple_t *t_list1 = NULL; 
    tuple_t *t_list2 = NULL;
    tuple_t *t_otr = NULL;
    tuple_t *t_inr = NULL;
    uint16_t otrIdx = 0, inrIdx = 1;
    sql_sel_table_qual_tuple(rec, rec->table[0], 0, &t_list1);
    t_otr = t_list1;
    if (rec->table[1]) {
        sql_sel_table_qual_tuple(rec, rec->table[1], 1, &t_list2);
        t_inr = t_list2;
        if (rec->outerTuple) {
            if (rec->outerIdx == 1) {
                t_otr = t_list2;
                t_inr = t_list1;
                otrIdx = 1;
                inrIdx = 0;
            }
        }
    }
    // join (must AND)
    if (rec->cmpJoin) {
        var_node_t var_otr;
        var_node_t *cmp_otr;
        attr_node_t *attr_otr;
        tuple_cnn_t *tplCnn = NULL, *tplCnnInr = NULL;
        tuple_cnn_t **tplCnnTmp = &tplCnnInr;
        char *attrName;
        if (rec->outerIdx == rec->cmpJoin->cmpL_tblIdx) {
            attrName = rec->cmpJoin->cmp->right->varchar_value;
            cmp_otr = rec->cmpJoin->cmp->left;
        } else {
            attrName = rec->cmpJoin->cmp->left->varchar_value;
            cmp_otr = rec->cmpJoin->cmp->right;
        }
        while (t_otr) {
            int nextQualNum = 0;
            attr_otr = t_otr->find_attr_vals(t_otr, cmp_otr->varchar_value);
            if (attr_otr) {
                var_otr.type = attr_otr->header->data_type;  
                var_otr.int_value = attr_otr->value->int_value;
                var_otr.varchar_value = attr_otr->value->varchar_value;
                sql_index_cb[IDX_CB_TYPE_EQUAL](rec->table[inrIdx], attrName, &var_otr, 4, NULL, &t_inr);
                if (t_inr) {
                    tuple_cnn_t *tail;
                    tplCnn = CALLOC_MEM(tuple_cnn_t, 1);
                    CALLOC_CHK(tplCnn);
                    nextQualNum = 0;
                    tplCnn->table = rec->table[otrIdx];
                    tplCnn->tuple = t_otr;
                    while (t_inr) {
                        *tplCnnTmp = CALLOC_MEM(tuple_cnn_t, 1);
                        CALLOC_CHK(*tplCnnTmp);
                        nextQualNum++;
                        tail = *tplCnnTmp;
                        (*tplCnnTmp)->table = rec->table[inrIdx];
                        (*tplCnnTmp)->tuple = t_inr;
                        tplCnnTmp = &((*tplCnnTmp)->siblNext);
                        t_inr = t_inr->next;
                    }
                    tplCnn->nextQualNum = nextQualNum;
                    tplCnn->nextRel = tplCnnInr;
                    tplCnn->siblHead = tplCnnInr;
                    tplCnn->siblTail = tail;
                    if (tplCnnInr)
                        tplCnnInr->prevRel = tplCnn;
                    sql_save_qual_tuple(rec, tplCnn);
                } 
            }
            t_otr = t_otr->next;
        }
    
    } else {
        // all condition in one table
        // one condition for each table
        tuple_cnn_t *tplCnn = NULL, *tplCnnInr = NULL;
        tuple_cnn_t **tplCnnTmp = &tplCnnInr;
        int nextQualNum = 0;
        while (t_otr) {
            tuple_cnn_t *tail;
            tplCnn = CALLOC_MEM(tuple_cnn_t, 1);
            CALLOC_CHK(tplCnn);
            nextQualNum = 0;
            tplCnn->table = rec->table[otrIdx];
            tplCnn->tuple = t_otr;
            while (t_inr) {
                *tplCnnTmp = CALLOC_MEM(tuple_cnn_t, 1);
                CALLOC_CHK(*tplCnnTmp);
                nextQualNum++;
                tail = *tplCnnTmp;
                (*tplCnnTmp)->table = rec->table[inrIdx];
                (*tplCnnTmp)->tuple = t_inr;
                tplCnnTmp = &((*tplCnnTmp)->siblNext);
                t_inr = t_inr->next;
            }
            tplCnn->nextQualNum = nextQualNum;
            tplCnn->nextRel = tplCnnInr;
            tplCnn->siblHead = tplCnnInr;
            tplCnn->siblTail = tail;
            if (tplCnnInr)
                tplCnnInr->prevRel = tplCnn;
            sql_save_qual_tuple(rec, tplCnn);
            t_otr = t_otr->next;
        }
    }
    return 0;
}

static inline char *sql_data_type_translate(data_type_e type)
{
    char *type_s = NULL;
    switch (type)
    {
        case DATA_TYPE_INT:
            type_s = "int";      
            break;
        case DATA_TYPE_VARCHAR:
            type_s = "string(varchar)";
            break;
        default:
            //printf("error: unknown data type\n");
            break;
    }
    return type_s;
}

static void sql_cret_tbl_add_prikey_attr(table_node_t *self, attr_node_header_t *attr)
{
    if (self->pkey_attr_tail) {
        self->pkey_attr_tail->next = attr;
        self->pkey_attr_tail = attr;
    } else {
        self->pkey_attr_head = attr;
        self->pkey_attr_tail = attr;
    }
}

static bool sql_cret_tbl_set_attr_list(table_node_t *self, attr_node_header_t *attr_node_hdr)
{
    attr_node_header_t *attrNdHdr = attr_node_hdr;
    attr_node_header_t *attrNdHdrNext = NULL;
    uint16_t attrNum = 0;
    while (attrNdHdr) {
        if (attrNum < MAX_ATTR_NUM) {
            self->attr[attrNum] = attrNdHdr;
            attrNdHdrNext = attrNdHdr->next;
            if (attrNdHdr->col_attr & ATTR_PRIKEY) {
                self->add_prikey_attr(self, attrNdHdr);
            }
            attrNum ++;
            attrNdHdr->next = NULL;
            attrNdHdr = attrNdHdrNext;
        } else {
            printf("error: too many attributes\n");
            return false;
        }
    }
    self->attr_num = attrNum;
    return true;
}

static void sql_cret_tbl_destroy_table(table_node_t *tbl)
{
    free(tbl);
}

static void sql_add_tuple_to_table(table_node_t *self, tuple_t *tuple) {
    if (self->tuple_list_head) {
        self->tuple_list_tail->next = tuple;
        self->tuple_list_tail = tuple;
    } else {
        self->tuple_list_head = tuple;
        self->tuple_list_tail = tuple;
    }
    //self->tuple_num++;
}


static table_node_t *sql_cret_tbl_table_create_and_init(char *name)
{
    table_node_t *tbl =  CALLOC_MEM(table_node_t, 1);
    CALLOC_CHK(tbl);
    tbl->name = name;
    tbl->set_attr = sql_cret_tbl_set_attr_list;
    tbl->add_prikey_attr = sql_cret_tbl_add_prikey_attr; 
    tbl->chk_col_list = sql_insr_check_col_list_valid;
    tbl->chk_duplc = sql_is_dup_tuple_chk;
    tbl->add_tuple = sql_add_tuple_to_table;
    tbl->find_attr = sql_insr_find_attr_in_table;
    return tbl;
}


unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    char *lower_str = (char *) malloc (sizeof(str));
    char *lstr = lower_str;
    int i = 0;
    
    for (i = 0; i < sizeof(str); i++) 
        *(lower_str+i) = tolower(*(str+i));
    *(lower_str+sizeof(str)) = '\0';
    while (*lower_str) {
            hash = hash * seed + (*lower_str++);
    }
    free(lstr);
    return (hash & 0x7FFFFFFF);
}

stmt_node_t *sql_create_stmt(stmt_type_e stmt_type, void *parsed_stmt)
{
    return NULL;
}

static void sql_stmt_save(stmt_node_t *self, stmt_type_e type, void *info)
{
    self->type = type;
    self->stmt_info = info;
}

stmt_node_t *sql_stmt_act_init()
{
    stmt_node_t *stmtNd = CALLOC_MEM(stmt_node_t, 1);
    CALLOC_CHK(stmtNd);
    stmtNd->stmt_save = sql_stmt_save;
    
    return stmtNd;
}

table_node_t *sql_find_table(char *table_name)
{
    if (table_name) {
        int bucket_idx = BKDRHash(table_name) % MAX_TABLE_ENTRY;
        table_node_t *table = table_list[bucket_idx];
        while (table) {
            if (strcasecmp(table_name, table->name) == 0) {
                break;
            }
            table = table->next;
        }
        return table;
    }
    return NULL;
}

// check if any missing primary key in the column list
bool sql_insr_check_col_list_valid(table_node_t *self, col_node_t *colNodeList)
{   
    col_node_t *colNd = colNodeList;
    char *attrName = NULL;
    if (self->pkey_attr_head) {
        attr_node_header_t *attrNd = self->pkey_attr_head; 
        while (attrNd) {
            attrName = attrNd->name;
            while (colNd) {
                if (strcasecmp(attrName, colNd->name) == 0) {
                    break;
                }
                colNd = colNd->next;
            }
            if (!colNd) {
                printf("error: cannot find the primary key : \"%s\" \n", attrName);
                return false;
            }
            attrNd = attrNd->next;
            colNd = colNodeList;
        }
    } else { // all attributes are treated as primary key
        int i;
        for (i = 0; i < self->attr_num; i++) {
            attrName = self->attr[i]->name;
            while (colNd) {
                if (strcasecmp(attrName, colNd->name) == 0) {
                    break;
                }
                colNd = colNd->next;
            }
            if (!colNd) {
                printf("error: cannot find the primary key : \"%s\" \n", attrName);
                return false;
            }
            colNd = colNodeList;
        }
    }
    return true;
}

attr_node_t *sql_find_attr_in_tuple(tuple_t *tuple_nd, char *name)
{
    int bucket_idx = BKDRHash(name) % MAX_TUPLE_ATTR_HASH_SIZE;   
    attr_node_t *attr_nd = tuple_nd->attr[bucket_idx];
    while( attr_nd && attr_nd->header && attr_nd->header->name) {
        if (strcasecmp(attr_nd->header->name, name) == 0) {
            return attr_nd;
        }
        attr_nd = attr_nd->next;
    }
    return NULL;
}
void sql_free_attr_list(attr_node_t *attr_node) {
    attr_node_t *attr_nd_prev = NULL;
    while (attr_node) {
        if (attr_node->header->data_type == DATA_TYPE_VARCHAR)
            free(attr_node->value->varchar_value);
        attr_nd_prev = attr_node;
        attr_node = attr_node->next;
        free(attr_nd_prev);
    }
}

void sql_free_attr_in_tuple(tuple_t * tuple)
{
   int i = 0;
   attr_node_t *attr_node = NULL;

   for (i = 0; i < MAX_TUPLE_ATTR_HASH_SIZE; i++)
   {
        sql_free_attr_list(tuple->attr[i]);
   }

}

void sql_free_attr_header_list(attr_node_header_t *attr_node)
{
    attr_node_header_t *attr_nd_prev = NULL;
    while (attr_node) {
        if (attr_node->name)
            free(attr_node->name);
        attr_nd_prev = attr_node;
        attr_node = attr_node->next;
        free(attr_nd_prev);
    }
}
bool sql_compare_two_attr_value(data_type_e type, attr_node_value_t *v1, attr_node_value_t *v2)
{
    bool rtn = false;
    switch (type)
    {
        case DATA_TYPE_INT:
            rtn = (v1->int_value == v2->int_value);
            break;
        case DATA_TYPE_VARCHAR:
            rtn = (strcasecmp(v1->varchar_value, v2->varchar_value) == 0);
            break;
        default:
            printf("error: unknown data type\n");
            break;
    }
    return rtn;
}
bool sql_compare_prikey_with_pkname(tuple_t *new_insr, tuple_t *old_insr, attr_node_header_t *pk_attr)
{
    attr_node_t *attr_new = new_insr->find_attr_vals(new_insr, pk_attr->name);   
    attr_node_t *attr_old = old_insr->find_attr_vals(old_insr, pk_attr->name); 
    
    if( attr_new && attr_old 
        && attr_new->header->data_type == attr_old->header->data_type
        && sql_compare_two_attr_value(attr_new->header->data_type, attr_new->value, attr_old->value)) {
        if (pk_attr->next)
            return sql_compare_prikey_with_pkname(new_insr, old_insr, pk_attr->next);
        else
            return true;
    }
    return false;
}

bool sql_compare_each_prikey(tuple_t *new, tuple_t *exist, attr_node_header_t *pk_attr)
{
    int i;
    for (i = 0; i < MAX_ATTR_NUM; i++) {
        if (!sql_compare_prikey_with_pkname(new, exist, pk_attr+i))
            return false;
    }
    return true;
}
// true: means duplicated tuple was created before
// we should free all the mem created for new insertion 
// free
bool sql_is_dup_tuple_chk(table_node_t *table, tuple_t *new_tuple)
{
    tuple_t *tuple_in_tbl = table->tuple_list_head;
    sql_cmp_two_tuple cmp_fun;
    attr_node_header_t *cmp_arg;
    if (table->pkey_attr_head) {
        cmp_fun = sql_compare_prikey_with_pkname;
        cmp_arg = table->pkey_attr_head;
    } else {
        cmp_fun = sql_compare_each_prikey;
        cmp_arg = table->attr[0];
    }
    while (tuple_in_tbl) {
        if (cmp_fun(new_tuple, tuple_in_tbl, cmp_arg))
            return true;
        tuple_in_tbl = tuple_in_tbl->next;
    }
    return false;
}
void sql_tuple_attr_insert(tuple_t *tuple, attr_node_t *attr_node)
{
    attr_node_t *attr_nd_next = NULL;
    int bucket_idx = -1;

    while (attr_node) {
        if (attr_node->header->name) {
            bucket_idx = BKDRHash(attr_node->header->name) % MAX_TUPLE_ATTR_HASH_SIZE;
            attr_nd_next = attr_node->next;
            if (bucket_idx >= 0) {
                attr_node->next = tuple->attr[bucket_idx];
                tuple->attr[bucket_idx] = attr_node;
            }
        } else {
            printf("error: attr_node miss name\n");
        }
        attr_node = attr_nd_next;
        bucket_idx = -1;
    }
}

attr_node_header_t *sql_insr_find_attr_in_table(table_node_t *tbl, char *attrName)
{
    int i;
    for (i = 0; i < tbl->attr_num; i++) {
        if (strcasecmp(tbl->attr[i]->name, attrName) == 0)            
            return tbl->attr[i];
    }
    return NULL;
}

bool sql_check_data_type_match(attr_node_header_t *attrHdr, data_type_e type)
{
    return (attrHdr->data_type == type);
}

bool sql_check_data_validation(attr_node_header_t *attrHdr, var_node_t *dataInfo)
{
    switch (dataInfo->type) 
    {
        case DATA_TYPE_VARCHAR:
            return (dataInfo->varchar_len <= attrHdr->varchar_len);
            break;
        case DATA_TYPE_INT:
        default:
            break;
    }
    return true;
}


static void sql_attr_node_add_header(attr_node_t *attr, attr_node_header_t *header)
{
    attr->header = header;
}

static bool sql_attr_node_set_value(attr_node_t *attr, var_node_t *vals)
{
    attr->value = CALLOC_MEM(attr_node_value_t, 1);
    CALLOC_CHK(attr->value);
    switch(vals->type)
    {
        case DATA_TYPE_INT:
            attr->value->int_value = vals->int_value;
            break;
        case DATA_TYPE_VARCHAR:
            attr->value->varchar_value = strdup(vals->varchar_value);
            attr->value->var_len = vals->varchar_len;
            break;
        default:
            printf("error:undefined datatype\n");
            return false;
            break;
    }
    return true;
}

attr_node_header_t *sql_attr_header_node_create_and_init(char *name)
{
    attr_node_header_t *newNd = CALLOC_MEM(attr_node_header_t, 1);
    CALLOC_CHK(newNd);
    newNd->name = name;
    newNd->is_data_valid = sql_check_data_validation; 
    newNd->is_type_match = sql_check_data_type_match;
    return newNd;
}
attr_node_t *sql_attr_node_create_and_init(attr_node_header_t *hdr)
{
    attr_node_t *attrNd = CALLOC_MEM(attr_node_t, 1);
    CALLOC_CHK(attrNd);
    attrNd->header = hdr;
    attrNd->add_hdr = sql_attr_node_add_header;
    attrNd->set_value = sql_attr_node_set_value;
    return attrNd;
}


bool sql_insr_create_attr_node_with_self_dfn_order(table_node_t *table, col_node_t *col_list, insert_vals_node_t *vals_list, attr_node_t **attrNdHead)
{
    bool rtn = true;
    insert_vals_node_t *valsNd = vals_list;
    attr_node_header_t *attrHdr = NULL;
    col_node_t *col = col_list;
    while (col) {
        if ((attrHdr = table->find_attr(table, col->name))) { 
            if (attrHdr->is_type_match(attrHdr, valsNd->info->type) 
                && attrHdr->is_data_valid(attrHdr, valsNd->info)) {
                attr_node_t *attrNd = sql_attr_node_create_and_init(attrHdr);
                rtn = attrNd->set_value(attrNd, valsNd->info) || !printf(" set value for a attr Node fail: %s\n", col->name);
                attrNd->next = *attrNdHead;
                *attrNdHead = attrNd;
                if(!rtn) return rtn;
            } else {
                return false;
            }
        }
        col = col->next;
        valsNd = valsNd->next;
    }
    return rtn;
}


bool sql_insr_create_attr_node_by_default(table_node_t *tbl, insert_vals_node_t *vals_list, attr_node_t **attrNdHead)
{
    insert_vals_node_t *valsNd = vals_list;
    int i;
    bool rtn = true;
    attr_node_header_t *attrHdr;
    for (i = 0; i < tbl->attr_num; i++) {
        if (valsNd && valsNd->info) {
            attrHdr = tbl->attr[i];
            if (attrHdr->is_type_match(attrHdr, valsNd->info->type) 
                && attrHdr->is_data_valid(attrHdr, valsNd->info)) {
                attr_node_t *attrNd = sql_attr_node_create_and_init(attrHdr);
                rtn = attrNd->set_value(attrNd, valsNd->info);
                attrNd->next = *attrNdHead;
                *attrNdHead = attrNd;
                if(!rtn) return rtn;
            } else {
                return false;
            }
        } else {
            printf("not enough VALUES\n");
            return false;
        }
        valsNd = valsNd->next;
    }
    if (valsNd) {
        printf("too many VALUES\n");
        return false;
    }
    return true;
}

static tuple_t *sql_tuple_create_and_init()
{
    tuple_t *tuple = CALLOC_MEM(tuple_t, 1);
    CALLOC_CHK(tuple);
    tuple-> add_attr_vals = sql_tuple_attr_insert;
    tuple->find_attr_vals = sql_find_attr_in_tuple;
    return tuple;
}

bool sql_insr_stmt_tuple_create(table_node_t *tbl, col_node_t *col_list, insert_vals_node_t *vals_list)
{
    attr_node_t *attrNdHead = NULL;
    bool result = true;
    if (col_list) {
        result = sql_insr_create_attr_node_with_self_dfn_order(tbl, col_list, vals_list, &attrNdHead);
    }
    else {
        result = sql_insr_create_attr_node_by_default(tbl, vals_list, &attrNdHead);
    }
    if (result && attrNdHead) {
        tuple_t *tuple = sql_tuple_create_and_init();
        tuple->add_attr_vals(tuple, attrNdHead);
        if (!tbl->chk_duplc(tbl, tuple)) {
            tbl->add_tuple(tbl, tuple);
            tbl->tuple_num++;
            db__table_info_tuple_save_in_mem(tbl, tuple);
            return true;
        } else {
            printf("duplicated\n");
        }
    } else {
        // fail to create a attrVals Node
    }
    return false;
}

#if 0
bool sql_data_info_valid_chk(table_node_t *table, col_node_t *col_node, insert_vals_node_t *vals_node)
{
    /* <with column list>
     * find the corresponding attr in table->attr
     * if it is found, 
     *  check the data type and validation 
     *  if ok, => creata a node => succeed
     *  if not, => error
     * else => error
     *
     * <without column list>
     * compare the table->attr one by one
     *  check the data type and validation 
     *  if ok, => creata a node => succeed
     *  if not, => error
     * 
     *  succeed: insert the node to table
     *  error: free all nodes we created for this insertion stmt
     *
     */

    //@input table, col, attr_node_t **head 

    // remember free col_node & var_node
    bool rtn = true;
    tuple_t *tuple_nd = NULL;
    attr_node_t *attr_nd = NULL;
    attr_node_t *attr_nd_prev = NULL;
    attr_node_t *attr_head = NULL;
    col_node_t *col = col_node;
    insert_vals_node_t *vals_nd = vals_node;
    int i = 0;
    bool is_match_name = false;

    if (col) {
        while (col && rtn) {
        for (i = 0; (i < table->attr_num) && rtn; i++) {
            if (strcasecmp(table->attr[i]->header->name, col->name) == 0) {
                is_match_name = true;
                var_node_t *var =  vals_nd->var_info;
                if ( table->attr[i]->header->data_type == var->type) {
                    if (var->type == DATA_TYPE_VARCHAR && 
                        var->varchar_len > table->attr[i]->header->varchar_len) {
                        rtn = false;
                        printf("error: varchar len is too long(%d), only %d allowed\n", 
                                    var->varchar_len, table->attr[i]->header->varchar_len);
                        break;
                    }
                    attr_nd = (attr_node_t *) malloc(sizeof(attr_node_t));
                    if (!attr_nd) {
                        printf("no heap meme\n");
                        rtn =false; 
                        break;
                    }
                    memset(attr_nd, 0, sizeof(attr_node_t));
                    attr_nd->header = table->attr[i]->header;
                    attr_nd->value = (attr_node_value_t *) malloc(sizeof(attr_node_value_t));
                    if (!attr_nd->value) {
                        printf("no heap meme\n");
                        rtn = false;
                    }
                    memset(attr_nd->value, 0, sizeof(attr_node_value_t));
                    switch(var->type)
                    {
                        case DATA_TYPE_INT:
                            attr_nd->value->int_value = var->int_value;
                            break;
                        case DATA_TYPE_VARCHAR:
                            attr_nd->value->varchar_value = strdup(var->varchar_value);
                            attr_nd->value->var_len = var->varchar_len;
                            break;
                        default:
                            printf("error:undefined datatype\n");
                            break;
                    }
                    if (rtn) {

                        if (!attr_head)
                            attr_head = attr_nd;
                        if (attr_nd_prev) {
                            attr_nd_prev->next = attr_nd;
                            attr_nd->prev = attr_nd_prev;
                        }
                        attr_nd_prev = attr_nd;
                    } else {
                        if (attr_nd->value)
                            free(attr_nd->value);
                        free(attr_nd);
                        attr_nd = NULL;
                    }
                    break;
                }
                else {
                    printf("data type does not match ");
                    printf("%s is needed, your insert %s\n", 
                            sql_data_type_translate(table->attr[i]->header->data_type), 
                            sql_data_type_translate(var->type));
                    rtn = false;
                }
            }
        }
        if (!is_match_name && !attr_nd) {
            printf("col name: %s does not match any attr\n", col->name);
            rtn = false;
        }
        is_match_name = false;
        col = col->next;
        vals_nd = vals_nd->next;
        }
    } else {
        int i = 0, attr_ok_num = 0;
        for (i = 0; (i < table->attr_num) && rtn; i++) {
            if(!vals_nd)
                break;
            var_node_t *var = vals_nd->var_info;
            if (!var)
                break;
            if (table->attr[i]->header->data_type == var->type) {
                attr_nd = (attr_node_t *) malloc(sizeof(attr_node_t));
                if (!attr_nd) {
                    printf("no heap meme\n");
                    rtn =false; 
                    break;
                }
                memset(attr_nd, 0, sizeof(attr_node_t));
                attr_nd->header = table->attr[i]->header;
                attr_nd->value = (attr_node_value_t *) malloc(sizeof(attr_node_value_t));
                if (!attr_nd->value) {
                    printf("no heap meme\n");
                    rtn = false;
                }
                memset(attr_nd->value, 0, sizeof(attr_node_value_t));
                switch(var->type)
                {
                    case DATA_TYPE_INT:
                        attr_nd->value->int_value = var->int_value;
                        break;
                    case DATA_TYPE_VARCHAR:
                        if (var->varchar_len <= attr_nd->header->varchar_len)
                            attr_nd->value->varchar_value = strdup(var->varchar_value);
                        else {
                            rtn = false;
                            printf("error: varchar len is too long(%d), only %d allowed\n", 
                                    var->varchar_len, attr_nd->header->varchar_len);
                        }
                        break;
                    default:
                        printf("error:undefined datatype\n");
                        break;
                }
                if (rtn) {
                    if (!attr_head)
                        attr_head = attr_nd;
                    if (attr_nd_prev) {
                        attr_nd_prev->next = attr_nd;
                        attr_nd->prev = attr_nd_prev;
                    }
                    attr_nd_prev = attr_nd;
                    attr_ok_num++;
                } else {
                    if (attr_nd->value) 
                        free(attr_nd->value);
                    free(attr_nd);
                    attr_nd = NULL;
                }
            } else {
                printf("error: data type does not match: ");
                printf("%s is needed, your insert %s\n", 
                        sql_data_type_translate(table->attr[i]->header->data_type), 
                        sql_data_type_translate(var->type));
                    rtn = false;
            }
            vals_nd = vals_nd->next;
        }
        if (rtn && (attr_ok_num < table->attr_num)) {
            printf("error: num of values is not enough\n");
            rtn = false;
        }
    }

    if (rtn && attr_head) {
        tuple_nd = (tuple_t *) malloc(sizeof(tuple_t));
        
        if (!tuple_nd) {
            printf("no heap mem\n");
            // free all the attr node just created;
            sql_free_attr_list(attr_head);
            //
        }
        memset(tuple_nd, 0, sizeof(tuple_t));
        sql_tuple_attr_insert(tuple_nd, attr_head);
        if (!table->tuple_list_head || !sql_is_dup_tuple_chk(tuple_nd, table)) {
            tuple_nd->next = NULL;
            tuple_nd->prev = NULL;
            if (!table->tuple_list_head) {
                table->tuple_list_head = tuple_nd;
            } else {
                table->tuple_list_tail->next = tuple_nd;
                tuple_nd->prev = table->tuple_list_tail;
            }
            table->tuple_list_tail = tuple_nd;
            table->tupleNum++;
        } else {
            // only for out a error message
            if (table->prim_key_num) {
                printf("primary key \n");
                attr_node_t *pk_attr   = table->prim_key_attr;
                attr_node_t *attr_find = NULL;
                while (pk_attr) {
                    if (pk_attr->header->name) {
                        printf("%s(", pk_attr->header->name);
                        attr_find = sql_find_attr_in_tuple(tuple_nd, pk_attr->header->name); 
                        if (attr_find && attr_find->value) {
                            switch (attr_find->header->data_type) 
                            {
                                case DATA_TYPE_INT:
                                    printf("%d)", attr_find->value->int_value);
                                    break;
                                case DATA_TYPE_VARCHAR:
                                    if(attr_find->value->varchar_value)
                                        printf("%s)", attr_find->value->varchar_value);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    printf("\n");
                    pk_attr = pk_attr->next;
                }
                printf("is duplicated\n");
            }
            else
                printf("tuple is duplicated\n");
            sql_free_attr_in_tuple(tuple_nd);
            free(tuple_nd);
        }
    } else {
        //free all the attr node just created
        sql_free_attr_list(attr_head);
    }

    return rtn;
}
#endif

stmt_node_t *sql_insert_stmt_create(char *table_name, col_node_t *col_name_list, insert_vals_node_t *insr_vals_list)
{
   
    insert_stmt_t *insrStmt = CALLOC_MEM(insert_stmt_t, 1);
    CALLOC_CHK(insrStmt);

    insrStmt->table_name = table_name;
    insrStmt->col_list = col_name_list;
    insrStmt->insr_vals_list = insr_vals_list;
    stmt_node_t *stmtNd = sql_stmt_act_init();
    stmtNd->stmt_save(stmtNd, STMT_TYPE_INSERT_TUPLE, (void *)insrStmt);
    return stmtNd;
}


static void sql_insert_stmt_free_mem(insert_stmt_t *insr_stmt)
{
    col_node_t *col_nd = insr_stmt->col_list;
    col_node_t *col_prev = NULL;
    insert_vals_node_t *vals_nd = insr_stmt->insr_vals_list;
    insert_vals_node_t *vals_prev = NULL;
    while (col_nd) {
        col_prev = col_nd;
        col_nd = col_nd->next;
        free(col_prev->name);
        free(col_prev);
    }
    while (vals_nd) {
        vals_prev = vals_nd;
        vals_nd = vals_nd->next;
        if (vals_prev->info) {
            if (vals_prev->info->varchar_value && vals_prev->info->type == DATA_TYPE_VARCHAR)
                free(vals_prev->info->varchar_value);
            free(vals_prev->info);
        }
        free(vals_prev);

    }
    free(insr_stmt->table_name);
    free(insr_stmt);
}

void sql_cret_tbl_add_table(table_node_t *table)
{
    int bkt = BKDRHash(table->name) % MAX_TABLE_ENTRY;
    table->next = table_list[bkt];
    table_list[bkt] = table;

}

bool sql_cret_table_stmt_handle(cret_tbl_stmt_t *cretTblStmt)
{
    table_node_t *tbl = NULL;
    if (sql_find_table(cretTblStmt->table_name)) {
        printf("error: the table : %s has been created before\n", cretTblStmt->table_name);
        return false;
    }
    tbl = sql_cret_tbl_table_create_and_init(cretTblStmt->table_name);
    if(!tbl->set_attr(tbl, cretTblStmt->attr_list)) {
        sql_cret_tbl_destroy_table(tbl);
        return false;
    }
    sql_cret_tbl_add_table(tbl);
    db__table_info_create(tbl);
    db__table_info_write(tbl);
    db__dbms_info_table_write(&dbms, tbl);
    
    tbl->curr_page++;
    sql_cret_tbl_page_init(tbl, tbl->curr_page);
    db__table_info_update(tbl);
    return true;

}

void sql_cret_tbl_page_init(table_node_t *tbl, uint16_t pageId)
{
    char *page;   
    tbl->pageTable[pageId].valid_bit = 1;
    tbl->pageTable[pageId].dirty_bit = 1;
    page = calloc(1, DB_PAGE_SIZE);
    *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_TYPE) = PAGE_TYPE_TUPLE;
    *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_OFFSET) = DB_PAGE_HEADER_SIZE;
    tbl->pageTable[pageId].page = page;
}

bool sql_create_idx_stmt_handle(cret_idx_stmt_t *cretIdxStmt)
{
    int ret;
    table_node_t *tbl = sql_find_table(cretIdxStmt->tblName);
    if (strstr(cretIdxStmt->idxName->name, "tree") != NULL) {
        ret = sql_set_table_idx_tree(&tbl->btree[tbl->btree_num].tree, tbl, cretIdxStmt->col_list);
        //TODO: insert file Name into btree.name;
        if (ret != BP_OK) goto fatal;
        tbl->btree_num++;
    } else if (strstr(cretIdxStmt->idxName->name, "hash") != NULL) {
        //0508
        ret = sql_set_table_idx_hash(tbl, cretIdxStmt->col_list);
        if(ret!=EH_OK) goto fatal;
        //tbl->hash_num++;// not yet add this var to table struct
        //0508
        //HL_TODO: create hash idx 
    } else {
        printf("Tree or Hash ?\n");
    }
fatal:
    return false;
}

bool sql_insert_stmt_handle(insert_stmt_t *insr_stmt)
{
    bool rtn = true;
    int result = 0;
    table_node_t *table = sql_find_table(insr_stmt->table_name);
    if (table) {
        if (insr_stmt->col_list) {
            rtn = table->chk_col_list(table, insr_stmt->col_list);
            if (result >0) {
                if (table->pkey_num)
                    printf("error: primary key(s) cannot be null\n ");
                else
                    printf("error: num of attr you insert is not enough\n");
            }
        }
        if (rtn && !sql_insr_stmt_tuple_create(table, insr_stmt->col_list, insr_stmt->insr_vals_list)) {
            printf("error: error in data input\n");
            rtn = false;
        }
    }
    else {
        printf("error: fails to find the table for table name: %s\n", insr_stmt->table_name);
        rtn = false;   
    }
    sql_output_insert_result_to_file(insr_stmt);
    
    return rtn;
    // check if NOT-NULL attr is NULL
}

void sql_stmt_handle(stmt_node_t *stmt)
{
    bool hdlPass = true;
    if (stmt) {
        switch(stmt->type)
        {
        case STMT_TYPE_CREATE_TABLE:
            hdlPass = sql_cret_table_stmt_handle((cret_tbl_stmt_t *)(stmt->stmt_info));

            break;
        case STMT_TYPE_INSERT_TUPLE:
            hdlPass = sql_insert_stmt_handle((insert_stmt_t *)(stmt->stmt_info));
            break;
        case STMT_TYPE_SELECT_TUPLE:
            hdlPass = sql_select_stmt_handle((select_stmt_t *)(stmt->stmt_info));
            break;
        case STMT_TYPE_CREATE_INDEX:
            hdlPass = sql_create_idx_stmt_handle((cret_idx_stmt_t *)(stmt->stmt_info));
        case STMT_TYPE_SHOW_LOG:
            //free(stmt);
        default:
            //printf("invalid stmt\n");
            break;
        }
        if(!hdlPass) stmt_dstry[stmt->type](stmt);
        free(stmt);
    }
}
char *sql_create_attr_varchar(int len)                   
{                                                        
    if (len <= 0)
        printf("the length varchar should be larger than zero\n");
    char *varchar_attr = (char *) malloc(sizeof(char)*len);
    return varchar_attr;                                 
}

stmt_node_t *sql_cret_table_stmt_create(char *table_name, attr_node_header_t *attr_list) 
{
    cret_tbl_stmt_t *cretTblStmt = CALLOC_MEM(cret_tbl_stmt_t, 1);
    CALLOC_CHK(cretTblStmt);

    cretTblStmt->table_name = table_name;
    cretTblStmt->attr_list = attr_list;

    stmt_node_t *stmtNd = sql_stmt_act_init();
    stmtNd->stmt_save(stmtNd, STMT_TYPE_CREATE_TABLE, (void *)cretTblStmt);
    return stmtNd;
}



attr_node_header_t  *sql_create_attr(char *name, int data_type, uint16_t col_attr)
{
    attr_node_header_t *newNd = sql_attr_header_node_create_and_init(name);
    if (data_type > DATA_TYPE_VARCHAR 
        && data_type <= (DATA_TYPE_VARCHAR + MAX_VARCHAR_LEN))     
    {
        newNd->varchar_len = data_type - DATA_TYPE_VARCHAR;
        newNd->data_type = DATA_TYPE_VARCHAR;
    }
    else if (data_type == DATA_TYPE_INT) {
        newNd->data_type = DATA_TYPE_INT;
    }
    
    newNd->col_attr = col_attr;
#if 0
    switch (c || attrHd->col_attrol_attr)
    {
        case COL_ATTR_PRIKEY:
            newNd->is_PRIKEY = true;
            break;
        case COL_ATTR_VALID:
            newNd->is_PRIKEY = false;
            break;
        case COL_ATTR_INVALID:
        default:
            newNd->is_PRIKEY = false;
            printf("invalid column attr.\n");
            break;
    }
#endif
    return newNd;
}

attr_node_header_t *sql_attr_head_set(attr_node_header_t *head_node)
{
    if (head_node) {
        head_node->head = head_node;
        head_node->tail = head_node;
    }   
    return head_node;
}
attr_node_header_t *sql_attr_collect(attr_node_header_t *list, attr_node_header_t *node)
{
    if (list){
        list->tail->next = node;   
        list->tail = node;
        return list;
    } else {
        node->head = node;
        node->tail = node;
        return node;
    }
}

void sql_printf_attr(attr_node_header_t *node)
{
#ifdef SDEBUG
    if (node) {
        printf("name=%s, dataType=%d\n", node->name, node->data_type);
    }
#endif
}

void sql_recursive_printf_node(attr_node_header_t *list)
{
#ifdef SDEBUG
    while (list) {
        printf("node name = %s\n", list->name);
        list = list->next;
    }
#endif
}



col_node_t *sql_col_list_node_create(char *name, col_node_t *list, bool is_head)
{
    
    col_node_t *cNode = CALLOC_MEM(col_node_t, 1);
    CALLOC_CHK(cNode);
    cNode->name = name;
    if (list) {
        list->tail->next = cNode;
        list->tail = cNode;
        return list;
    } else {
        cNode->tail = cNode;
        cNode->head = cNode;
        return cNode;
    }
}

insert_vals_node_t *sql_insert_vals_node_create(expr_node_t *expr_node, insert_vals_node_t *list, bool is_head)
{
    insert_vals_node_t *insr_node = CALLOC_MEM(insert_vals_node_t, 1);
    CALLOC_CHK(insr_node);
    if (expr_node && expr_node->type == EXPR_TYPE_BASIC_VAR && expr_node->expr_info)
        insr_node->info = (var_node_t *)(expr_node->expr_info);
    insr_node->next = NULL;
    if (is_head) {
        insr_node->head = insr_node;
        insr_node->tail = insr_node;
        return insr_node;
    }
    else {
        insr_node->head = NULL;
        insr_node->tail = NULL;
        list->tail->next = insr_node;
        list->tail = insr_node;
        return list;
    }
}


expr_node_t *sql_expr_basic_data_node_create(data_type_e type, int int_val, char *varchar_val, char *prefix_val)
{
    var_node_t *data = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(data);
    switch(type) 
    {
        case DATA_TYPE_INT:
            data->int_value = int_val;
            break;
        case DATA_TYPE_VARCHAR:
            data->varchar_value = strdup(varchar_val);
            data->varchar_len = strlen(varchar_val)-2;
            break;
        case DATA_TYPE_NAME:
            data->varchar_value = strdup(varchar_val);
            data->varchar_len = strlen(varchar_val);
            break;
        //0401
        case DATA_TYPE_PREFIX:
            data->varchar_value = strdup(varchar_val);
            data->varchar_len = strlen(varchar_val);
            data->prefix_value = strdup(prefix_val);
            data->prefix_len = strlen(prefix_val);
            break;
        default:
            break;
    }
    data->type =  type;
    
    expr_node_t *expr_node = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(expr_node);
    expr_node->type = EXPR_TYPE_BASIC_VAR;
    expr_node->expr_info = (void *)data;
    return expr_node;
}


void sql_print_col_node(col_node_t *list)
{
    while (list) {
        printf("column name: %s\n", list->name);
        list = list->next;
    }
}
void sql_print_table(table_node_t *table)
{
    if (table) {
        tuple_t *tuple_nd = NULL;
        attr_node_t *attr_nd = NULL; 
        unsigned int bucket_idx = 0;
        bool is_find = false;
        int tupleNum = table->tuple_num;
        printf("table name: %s\n", table->name);
        int i = 0;
        for (i = 0; i < table->attr_num; i++) {
            printf("\t%s", table->attr[i]->name);
            if(table->attr[i]->col_attr&ATTR_PRIKEY)
                printf("(P)");
        }
        printf("\n");
        if (tupleNum) {
        tuple_nd = table->tuple_list_head;
            while (tuple_nd && tupleNum > 0) {
                for (i = 0; i < table->attr_num; i++) {
                    bucket_idx = BKDRHash(table->attr[i]->name) % MAX_TUPLE_ATTR_HASH_SIZE;
                    attr_nd = tuple_nd->attr[bucket_idx];
                    while( attr_nd && attr_nd->header && attr_nd->header->name) {
                        if (strcasecmp(attr_nd->header->name, table->attr[i]->name) == 0) {
                            is_find = true;
                            break;
                        }
                        attr_nd = attr_nd->next;
                    }
                    if (is_find) {
                
                        is_find = false;
                        if(attr_nd->header->data_type == DATA_TYPE_VARCHAR ) // TODO: may not be right
                            printf("\t%s", attr_nd->value->varchar_value);
                        else
                            printf("\t%d", attr_nd->value->int_value);
                    
                    } else {
                        printf("\tnull");
                        printf("what?\n");
                    }
                }
                tuple_nd = tuple_nd->next;
                tupleNum--;
                printf("\n");
            }
            printf("total:%d\n", table->tuple_num);
        }
    } else {
        printf("error: can not find the tablew\n");
    }
}

stmt_node_t *sql_show_table_content(char *name)
{
    table_node_t *table = NULL;
    tuple_t *tuple_nd = NULL;
    attr_node_t *attr_nd = NULL; 
    unsigned int bucket_idx = 0;
    bool is_find = false;
    if (name)
        table = sql_find_table(name);
    else {
        printf("table name is NULL\n");
        return NULL;
    }

    if (table) 
    	sql_print_table(table);
    else
        printf("error: can not find the table:%s\n", name);

    stmt_node_t *stmt = sql_stmt_act_init();
    sql_stmt_save(stmt, STMT_TYPE_SHOW_LOG, NULL);
    return stmt;
}

void sql_output_insert_result_to_file(insert_stmt_t *insr_stmt)
{
#ifdef SDEBUG
    sql_show_table_content(insr_stmt->table_name);
#endif
}
stmt_node_t *sql_show_all_table(void)
{
    int i = 0;
    int j = 0;//0509
    col_node_t col_node;//0509
    table_node_t *table = NULL;
    stmt_node_t *stmt = NULL;
    for (i = 0; i < MAX_TABLE_ENTRY; i++) {
        table = table_list[i];
        while (table) {
            if (table->name) {
                stmt = sql_show_table_content(table->name);
                if(stmt)
                    free(stmt);
            }
            db__table_info_update(table);
            db__table_info_all_pages_write(table);
            ///////// initialize hash index
            for(j=0; j<table->attr_num; j++){
                col_node.name = table->attr[j]->name;
                if(sql_set_table_idx_hash(table, &col_node)==EH_OK){
                    printf("create and insert to hash index: %s_%s_hash.idx: succeed\n", table->name, col_node.name);
                }
                else{
                    printf("create and insert to hash index: %s_%s_hash.idx:failed\n", table->name, col_node.name);
                }
            }
            
            
            /////////0509
            table = table->next;
            printf("\n");
            
        }
    }
    stmt = sql_stmt_act_init();
    sql_stmt_save(stmt, STMT_TYPE_SHOW_LOG, NULL);
    return stmt;
}
cret_def_node_t * sql_cret_def_attr_declar_node_create(char *name, int data_type, uint16_t col_attr)
{
    cret_def_node_t *cretNd = CALLOC_MEM(cret_def_node_t, 1);
    CALLOC_CHK(cretNd);

    cretNd->type = CREATE_DEF_TYPE_ATTR;
    cretNd->cret_def_info = sql_create_attr(name, data_type, col_attr);

    return cretNd;
}
cret_def_node_t *sql_cret_def_pk_def_node_create(col_node_t *cNode)
{
    cret_def_node_t *cretNd = CALLOC_MEM(cret_def_node_t, 1);
    CALLOC_CHK(cretNd);

    cretNd->type = CREATE_DEF_TYPE_PK_COL_LIST;
    cretNd->cret_def_info = (void *)cNode;
    return cretNd;
}

static bool sql_cret_def_pk_set(attr_node_header_t *list, col_node_t * col_list)
{
    // need free all the mem;
#if 0
    col_node_t *col_nd = col_list;
    col_node_t *col_nd_prev = NULL;
    attr_node_header_t *attr_nd = list;
    bool is_pk_exist = false, is_error = false;
    while (col_nd) {
        if ((!is_error) && col_nd->name) {
            while (attr_nd && attr_nd->name) {
                if(strcasecmp(attr_nd->name, col_nd->name) == 0) {
                    attr_nd->is_PRIKEY = true;
                    is_pk_exist = true;
                    break;
                }
                attr_nd = attr_nd->next;
            }
            if (!is_pk_exist) {
                printf("primary key : %s is not an attr\n", col_nd->name);
                is_error = true;
            }
        } 
        attr_nd = list;
        col_nd_prev = col_nd;
        col_nd = col_nd->next;
        free(col_nd_prev->name);
        free(col_nd_prev);
        if(is_pk_exist)
            is_pk_exist = false;
    }
#endif
    //return (is_error==false);
    return true;
    printf("compare if attr in prikey list are also in col list\n");
}

attr_node_header_t *sql_cret_def_handle(attr_node_header_t *list, cret_def_node_t *cret_def_node)
{
    attr_node_header_t *rtnNd = NULL;
    switch (cret_def_node->type)
    {
    case CREATE_DEF_TYPE_PK_COL_LIST:
        sql_cret_def_pk_set(list, (col_node_t *)(cret_def_node->cret_def_info));   
        break;
    case CREATE_DEF_TYPE_ATTR:
        rtnNd = sql_attr_collect(list, (attr_node_header_t *)(cret_def_node->cret_def_info));
        break;
    default :
        assert(0 && "unknown create def type\n");
        break;
    }
    return rtnNd;
}

void sql_free_col(col_node_t *cNd)
{
    if (cNd) {
        if (cNd->next)
            sql_free_col(cNd->next);
        free(cNd->name);
        free(cNd);
    }
}

void sql_free_insr_vals_node(insert_vals_node_t * vNd)
{
    if (vNd) {
        if (vNd->next)
            sql_free_insr_vals_node(vNd->next);
        free(vNd->info->varchar_value);
        free(vNd->info);
        free(vNd);
    }    
}

void sql_free_attr_hdr_list(attr_node_header_t *attrNdHdr)
{
    if (attrNdHdr) {
        if (attrNdHdr->next)
            sql_free_attr_hdr_list(attrNdHdr->next);
        free(attrNdHdr->name);
        free(attrNdHdr);
    }
}
void sql_cret_tbl_stmt_destroy(stmt_node_t *stmtNd)
{
    cret_tbl_stmt_t *cretTblStmt = (cret_tbl_stmt_t *)stmtNd->stmt_info;
    attr_node_header_t *attrNdHdr =  cretTblStmt->attr_list;
    sql_free_attr_hdr_list(attrNdHdr);
    free(cretTblStmt->table_name);
}

void sql_insr_tpl_stmt_destroy(stmt_node_t *stmtNd)
{
    insert_stmt_t *insrStmt = (insert_stmt_t *)stmtNd->stmt_info;
    col_node_t *col = insrStmt->col_list;
    insert_vals_node_t *vals = insrStmt->insr_vals_list;
    sql_free_col(col);
    sql_free_insr_vals_node(vals);
    free(insrStmt->table_name);
}

void  sql_cret_idx_stmt_destroy(stmt_node_t *stmtNd)
{
    cret_idx_stmt_t *cretIdxStmt = (cret_idx_stmt_t *)stmtNd->stmt_info;
    sql_free_col(cretIdxStmt->idxName);
    sql_free_col(cretIdxStmt->col_list);
    free(cretIdxStmt->tblName);
}

//0401//0405//
select_col_node_t *sql_select_col_node_create(expr_node_t *expr_node, char *alias_name, bool is_prefix_dot_star){
    //return a col_node to select_expr->select_expr_list->select_stmt
    select_col_node_t *select_col_node = CALLOC_MEM(select_col_node_t, 1);
    CALLOC_CHK(select_col_node);
    /* if the format is prefix.* */
    if(is_prefix_dot_star){
        var_node_t *var_node = CALLOC_MEM(var_node_t, 1);
        CALLOC_CHK(var_node);
        var_node->type = DATA_TYPE_PREFIX_STAR;
        var_node->prefix_value = strdup(alias_name);
        var_node->prefix_len = strlen(alias_name);
        
        select_col_node->is_prefix_dot_star  = true;
        select_col_node->col_info = var_node;
        select_col_node->is_star = false;
        select_col_node->is_aggregation = false;
        return select_col_node;
    }
    /*else*/
    if(alias_name){
        select_col_node->alias_name = strdup(alias_name);
    }   
    else{
        select_col_node->alias_name = NULL;
    }//0409
    select_col_node->is_star = false;
    select_col_node->is_prefix_dot_star  = false;

    if (expr_node == NULL || (expr_node->type != EXPR_TYPE_BASIC_VAR && expr_node->type != EXPR_TYPE_AGGREGATION ) || expr_node->expr_info == NULL) {
        free(select_col_node);
        printf("\nexpr is wrong!!!--sql_select_col_node_create()\n");
        return NULL;
    }
    else {
        if(expr_node->type == EXPR_TYPE_AGGREGATION )
            select_col_node->is_aggregation = true;
        else
            select_col_node->is_aggregation = false;
        select_col_node->col_info = (void *)expr_node->expr_info;
        return select_col_node;
    }
}//0401//0405

select_col_node_t *sql_select_col_list_create(select_col_node_t *col_node, select_col_node_t *list, bool is_head, bool is_star){
    //return a head col_node to select_expr_list->select_stmt
    if(is_star){
        select_col_node_t *select_col_node = CALLOC_MEM(select_col_node_t, 1);
        CALLOC_CHK(select_col_node);
        select_col_node->is_star = true;
        select_col_node->head = select_col_node;
        select_col_node->tail = select_col_node;
        select_col_node->next = NULL;
        return select_col_node;
    }
    
    if(col_node){
        if(is_head){
            col_node->head = col_node;
            col_node->tail = col_node;
            col_node->next = NULL;
            return col_node;
        }
        else{
            list->tail->next = col_node;
            list->tail = col_node;
            col_node->next = NULL;
            return list;
        }
    }
    else{
        printf("\ncol_node is NULL!!!---sql_select_col_list_create()\n");
        return NULL;
    }
}//0401//0405//

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
select_table_node_t* sql_select_table_node_create(char *table_name, char *prefix, char *alias_name)
{
    //return a table_node to table_factor->table_reference->table_references->select_stmt
    /*Error condition*/
    if(table_name == NULL){
        printf("\nError: table_name is NULL in sql_select_table_node_create().\n");
        return NULL;
    }
    select_table_node_t *table_node = CALLOC_MEM(select_table_node_t, 1);
    CALLOC_CHK(table_node);
    var_node_t *var_node = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(var_node);
    
    if (alias_name)
        table_node->alias_name = strdup(alias_name);
    else
        table_node->alias_name = NULL;
    
    //Check whether it is prefix type or not.
    if (prefix) {
        var_node->type = DATA_TYPE_PREFIX;
        var_node->varchar_value = strdup(table_name);
        var_node->varchar_len = strlen(table_name);
        var_node->prefix_value = strdup(prefix);
        var_node->prefix_len = strlen(prefix);
        table_node->table_info = var_node;
        
    }
    else {
        var_node->type = DATA_TYPE_VARCHAR;
        var_node->varchar_value = strdup(table_name);
        var_node->varchar_len = strlen(table_name);
        table_node->table_info = var_node;
   }
   return table_node;
}

select_table_node_t* sql_select_table_list_create(select_table_node_t *table_node, select_table_node_t *list, bool is_head)
{
    //return a head table_node to table_references->select_stmt
    /*Refered to sql_col_list_node_create() */
    /*Error condition*/
    if(table_node == NULL){
        printf("\nError: talbe_node is NULL in sql_select_table_list_create().\n");
        return NULL;
    }
    
    if (is_head) {
        table_node->head = table_node;
        table_node->tail = table_node;
        table_node->next = NULL;
        return table_node;
    }
    else {
        list->tail->next = table_node;
        list->tail = table_node;
        table_node->head = list;
        table_node->tail = table_node;
        table_node->next = NULL;
        return list;
   }
}//0401//0405

expr_node_t* sql_expr_comparison_node_create(cmp_type_e cmp_type, expr_node_t* left, expr_node_t* right)
{
    //expr_info in the expr_node returned is a cmp_node
    //return a expr_node to expr->opt_where->select_stmt
    
    /*Error condition*/
    if (left ==NULL || left->type != EXPR_TYPE_BASIC_VAR || left->expr_info == NULL){
        printf("\nError: \"left\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    if (right ==NULL || right->type != EXPR_TYPE_BASIC_VAR || right->expr_info == NULL){
        printf("\nError: \"right\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    
    /*Countruct comparison_node*/
    comparison_node_t *comparison_node = CALLOC_MEM(comparison_node_t, 1); 
    CALLOC_CHK(comparison_node);
    comparison_node->type = cmp_type;
    comparison_node->left = (var_node_t *)left->expr_info;
    comparison_node->right = (var_node_t *)right->expr_info;
    
    /*Countruct expr_node*/
    expr_node_t *expr_node = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(expr_node);
    expr_node->type = EXPR_TYPE_COMPARISON;
    expr_node->expr_info = (void *)comparison_node;
    return expr_node;
    
}//0401//0405

expr_node_t* sql_expr_logic_node_create(lgc_type_e lgc_type, expr_node_t* left, expr_node_t* right)
{
    //expr_info in the expr_node returned is a lgc_node
    //return a expr_node to expr->opt_where->select_stmt
    
    /*Error condition*/
    if (left ==NULL || left->expr_info == NULL){
        printf("\nError: \"left\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    if (right ==NULL || right->expr_info == NULL){
        printf("\nError: \"right\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    
    /*Countruct logic_node*/
    logic_node_t *logic_node = CALLOC_MEM(logic_node_t, 1);
    CALLOC_CHK(logic_node);
    logic_node->type = lgc_type;
    logic_node->left = left;
    logic_node->right = right;
    /*Countruct expr_node*/
    expr_node_t *expr_node = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(expr_node);
    expr_node->type = EXPR_TYPE_LOGIC;
    expr_node->expr_info = (void *)logic_node;
    return expr_node;
}//0401//0405

stmt_node_t *sql_select_stmt_create(stmt_type_e stmt_type, select_col_node_t* select_col_list, select_table_node_t* select_table_list, expr_node_t* select_qualifier)
{
    /*Error condition*/
    if (select_col_list == NULL){
        printf("\nError: \"select_col_list\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    if (select_table_list == NULL || select_table_list->table_info == NULL){
        printf("\nError: \"select_table_list\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    
    stmt_node_t *stmt_nd = NULL;
    select_stmt_t *select_stmt = NULL;
    stmt_nd = sql_stmt_act_init();
    if (!stmt_nd) {
        printf("\nno heap mem in sql_select_table_list_create().\n");
        return NULL;
    }
    select_stmt = (select_stmt_t *) malloc(sizeof(select_stmt_t));
    if (!select_stmt) {
        printf("\nno heap mem in sql_select_table_list_create().\n");
        free(stmt_nd);
        return NULL;
    }
    select_stmt->select_col_list = select_col_list;
    select_stmt->select_table_list = select_table_list;
    select_stmt->select_qualifier = select_qualifier;
    
    stmt_nd->stmt_save(stmt_nd, stmt_type, (void *)select_stmt);
    return stmt_nd;
}//0401//0405


bool sql_sel_collect_attr(sel_rec_t *rec, select_col_node_t* colList)
{
    sel_attr_t *alp = NULL;
    select_col_node_t* clp = colList;
    bool firstTime = 1;
    while (clp != NULL){
        /*Create new attr node.*/
        sel_attr_t *attr_node = CALLOC_MEM(sel_attr_t, 1);
        CALLOC_CHK(attr_node);
        if (firstTime){
            rec->attr_list = attr_node;
            alp = attr_node;
            alp->next = NULL;
            firstTime = false;
        }
        else {
            alp->next = attr_node;
            alp = alp->next;
            alp->next = NULL;
        }
        /*Check the col node is what kind of attr node.*/
        if (clp->is_star){
            alp->isAggregation = 0;
            alp->isPrintAll = true;
            alp->table_Name = NULL; /* for the case prefix.* , the tableName of its attr_node will not be NULL.*/
            alp->attr_Name = NULL;
            alp->output_Name = NULL;
        }
        else if (clp->is_prefix_dot_star){
            alp->isAggregation = 0;
            alp->isPrintAll = true;
            alp->table_Name =sql_sel_find_tbl_name(rec, ((var_node_t*)clp->col_info)->prefix_value ); 
            alp->attr_Name = NULL;
            alp->output_Name = strdup(((var_node_t *)clp->col_info)->prefix_value);
        }
        else if(clp->is_aggregation){
            alp->isAggregation = ((aggregation_node_t*)clp->col_info)->type;
            if (((aggregation_node_t*)clp->col_info)->is_star){
                alp->isPrintAll = true;
                alp->table_Name = NULL;
                alp->attr_Name = NULL;
                alp->output_Name = CALLOC_MEM(char, 10);
                CALLOC_CHK(alp->output_Name);
                if (((aggregation_node_t*)clp->col_info)->type == AGGR_TYPE_COUNT)
                    strcpy(alp->output_Name, "COUNT(*)");
                else
                    strcpy(alp->output_Name, "SUM(*)");
                    
            }
                
            else {
                alp->isPrintAll = false;
                if (((aggregation_node_t*)clp->col_info)->attr_info->type == DATA_TYPE_PREFIX){
                    
                    alp->table_Name = sql_sel_find_tbl_name(rec,  ((aggregation_node_t*)clp->col_info)->attr_info->prefix_value ); 
                    alp->attr_Name = ((aggregation_node_t*)clp->col_info)->attr_info->varchar_value;
                    
                    alp->output_Name = CALLOC_MEM(char, 100);
                    CALLOC_CHK(alp->output_Name);
                    if (((aggregation_node_t*)clp->col_info)->type == AGGR_TYPE_COUNT){
                        strcpy(alp->output_Name, "COUNT(");
                        strcat(alp->output_Name, ((aggregation_node_t*)clp->col_info)->attr_info->prefix_value);
                        strcat(alp->output_Name, ".");
                        strcat(alp->output_Name, alp->attr_Name);
                        strcat(alp->output_Name, ")");
                    }
                    else {
                        strcpy(alp->output_Name, "SUM(");
                        strcat(alp->output_Name, ((aggregation_node_t*)clp->col_info)->attr_info->prefix_value);
                        strcat(alp->output_Name, ".");
                        strcat(alp->output_Name, alp->attr_Name);
                        strcat(alp->output_Name, ")");
                    }
                }
                else if (((aggregation_node_t*)clp->col_info)->attr_info->type == DATA_TYPE_NAME) {
                    int i;
                    for(i = 0; i < MAX_SELECT_JOIN_TABLE; i++){ /*Checkout what table this attr is in*/
                        if(rec->table[i]->find_attr(rec->table[i], ((aggregation_node_t*)clp->col_info)->attr_info->varchar_value)){
                            alp->table_Name = rec->table[i]->name; 
                            break;
                        }
                    }
                    alp->output_Name = CALLOC_MEM(char, 100);
                    CALLOC_CHK(alp->output_Name);
                    alp->attr_Name = ((aggregation_node_t*)clp->col_info)->attr_info->varchar_value;
                    if (((aggregation_node_t*)clp->col_info)->type == AGGR_TYPE_COUNT){
                        strcpy(alp->output_Name, "COUNT(");
                        strcat(alp->output_Name, alp->attr_Name);
                        strcat(alp->output_Name, ")");
                    }
                    else {
                        strcpy(alp->output_Name, "SUM(");
                        strcat(alp->output_Name, alp->attr_Name);
                        strcat(alp->output_Name, ")");
                    }
                    
                }
                
            }
        }/*End of aggregation condition*/
        else{/*A normal select attr*/
            alp->isAggregation = 0;
            alp->isPrintAll = false;
            if (((var_node_t*)clp->col_info)->type == DATA_TYPE_PREFIX){
                
                alp->table_Name = sql_sel_find_tbl_name(rec, ((var_node_t*)clp->col_info)->prefix_value); 
                alp->attr_Name = ((var_node_t*)clp->col_info)->varchar_value;
                
                alp->output_Name = CALLOC_MEM(char, 100);
                CALLOC_CHK(alp->output_Name);
                strcpy(alp->output_Name, ((var_node_t*)clp->col_info)->prefix_value);
                strcat(alp->output_Name, ".");
                strcat(alp->output_Name, alp->attr_Name);
                
            }
            else if (((var_node_t*)clp->col_info)->type == DATA_TYPE_NAME) {
                int i;
                for(i = 0; i < MAX_SELECT_JOIN_TABLE; i++){ /*Checkout what table this attr is in*/
                    if(rec->table[i]->find_attr(rec->table[i], ((var_node_t*)clp->col_info)->varchar_value)){
                        alp->table_Name = rec->table[i]->name; 
                        break;
                    }
                }
                alp->output_Name = CALLOC_MEM(char, 100);
                CALLOC_CHK(alp->output_Name);
                alp->attr_Name = ((var_node_t*)clp->col_info)->varchar_value;
                strcpy(alp->output_Name, alp->attr_Name);
            }
        }
        
        
        clp = clp->next;
    }/*End of while loop*/
    //printAttrList(rec);
    return true;
}

void printAttrList(sel_rec_t *rec)
{
    sel_attr_t *attr_node = rec->attr_list;
    int c = 0;
    while(attr_node != NULL)
    {
        printf("\nAttr %d:\n", c++);
        printf("output_Name: %s\n", attr_node->output_Name);
        if(attr_node->isPrintAll){
            printf("isAggregation: %d\n", attr_node->isAggregation);
            printf("isPrintAll: %d\n", attr_node->isPrintAll);
            if(attr_node->table_Name != NULL)
                printf("table_Name: %s\n", attr_node->table_Name);
        }
        else if(attr_node->isAggregation){
            printf("isAggregation: %d\n", attr_node->isAggregation);
            printf("isPrintAll: %d\n", attr_node->isPrintAll);
            if(attr_node->table_Name != NULL)
                printf("table_Name: %s\n", attr_node->table_Name);
            if(attr_node->attr_Name != NULL)
                printf("attr_Name: %s\n", attr_node->attr_Name);
        }
        else{
            printf("isAggregation: %d\n", attr_node->isAggregation);
            printf("isPrintAll: %d\n", attr_node->isPrintAll);
            printf("table_Name: %s\n", attr_node->table_Name);
            printf("attr_Name: %s\n", attr_node->attr_Name);
        }
        attr_node = attr_node->next;
    }
}

/******/

char *sql_sel_find_tbl_name(sel_rec_t *rec, char *pfx)
{
    map_table_name_t *mapTbl = rec->mapTbl;
    while (mapTbl) {
        if (((mapTbl->tableName) && strcmp(mapTbl->tableName, pfx)== 0) 
          || (mapTbl->alias && strcmp(mapTbl->alias, pfx) == 0))
            return mapTbl->tableName;
        mapTbl = mapTbl->next;
    }
    return NULL;
}

char *sql_sel_find_alias_name(sel_rec_t *rec, char *tblName)
{
    map_table_name_t *mapTbl = rec->mapTbl;
    while (mapTbl) {
        if ((mapTbl->tableName) && strcmp(mapTbl->tableName, tblName) == 0)
            return mapTbl->alias;
        mapTbl = mapTbl->next;
    }
    return NULL;
}
bool sql_sel_collect_table(sel_rec_t *rec, select_table_node_t *tableList)
{
    int i = 0;
    /*Should initialize rec->table here.*/
    for(i = 0; i < MAX_SELECT_JOIN_TABLE; i++){
        rec->table[i] = NULL;
    }
    i = 0;
    table_node_t *table = NULL;
    select_table_node_t *selTable = tableList;
    map_table_name_t *mapTbl;
    map_table_name_t **mapTblHd = &mapTbl;
    while (selTable) {
        table = sql_find_table(selTable->table_info->varchar_value);
        if (table) {
            *mapTblHd = CALLOC_MEM(map_table_name_t, 1);
            CALLOC_CHK(*mapTblHd);
            (*mapTblHd)->alias = selTable->alias_name;
            (*mapTblHd)->tableName = selTable->table_info->varchar_value;
            (*mapTblHd)->next = NULL;
            rec->table[i] = table;
            i++;
            mapTblHd = &((*mapTblHd)->next);
        } else {
            //ERROR
            return false;
        }
        selTable = selTable->next;
    }
    rec->tableNum = i;
    rec->mapTbl = mapTbl;
    return true;
}

char *sql_transl_alias(char *alias)
{
    return "on working\n";
}
int sql_find_table_index_in_rec(sel_rec_t *rec, var_node_t *var)
{
        int i = 0;
        int matchNum = 0;
        int matchIdx = -1;
        char *tableName = NULL;
        if (var->type == DATA_TYPE_PREFIX) {
            tableName = sql_sel_find_tbl_name(rec, var->prefix_value);
        }   
        for (i = 0; i < MAX_SELECT_JOIN_TABLE; i++)
        {
            if (rec->table[i] && sql_insr_find_attr_in_table(rec->table[i], var->varchar_value)) {
                
                if (var->type == DATA_TYPE_PREFIX && strcasecmp(rec->table[i]->name, tableName)==0) {
                    return i;
                }
                else if (var->type == DATA_TYPE_NAME) {
                    matchNum++;
                    matchIdx = i;
                }
            }
        }

        if ( matchNum != 1 ) {
            //ERROR
            return -1;
        }
        return matchIdx;
    }

    void sql_save_cmp_for_tbl_in_rec(sel_rec_t *rec, comparison_node_t *cmp, lgc_type_e lgcType, int idx)
{
     cmp_eval_t *cmpEval = CALLOC_MEM(cmp_eval_t, 1);
     CALLOC_CHK(cmpEval);
     cmpEval->type = lgcType;
     cmpEval->cmp  = cmp;
     rec->cmpTblNum[idx]++;
     if (!rec->cmpForTbl[idx].head) {
        rec->cmpForTbl[idx].head = cmpEval;
        rec->cmpForTbl[idx].tail = cmpEval;
     } else {
        rec->cmpForTbl[idx].tail->next = cmpEval;
        rec->cmpForTbl[idx].tail = cmpEval;
     }
}

void sql_save_cmp_join_in_rec(sel_rec_t *rec, comparison_node_t *cmp, lgc_type_e lgcType, int idx, int idx2)
{
     cmp_eval_t *cmpEval = CALLOC_MEM(cmp_eval_t, 1);
     CALLOC_CHK(cmpEval);
     cmpEval->type = lgcType;
     cmpEval->cmp  = cmp;
     cmpEval->cmpL_tblIdx = idx;
     cmpEval->cmpR_tblIdx = idx2;
     cmpEval->next = rec->cmpJoin;
     rec->cmpJoin = cmpEval;
}

void sql_sel_collect_qual(sel_rec_t *rec, expr_node_t *exprList, lgc_type_e lgcType)
{
    if (!exprList)
        rec->isNoWhere = true;
    else {
        if (exprList->type == EXPR_TYPE_COMPARISON) {
            comparison_node_t *cmp = (comparison_node_t *)exprList->expr_info;
            int idx = -1;
            int idx2 = -1;
            int varType = -1;
        
            if ((cmp->left->type == DATA_TYPE_PREFIX || cmp->left->type == DATA_TYPE_NAME) 
                && (cmp->right->type == DATA_TYPE_PREFIX || cmp->right->type == DATA_TYPE_NAME)) {
                idx = sql_find_table_index_in_rec(rec, cmp->left);
                idx2 = sql_find_table_index_in_rec(rec, cmp->right);
                sql_save_cmp_join_in_rec(rec, cmp, lgcType, idx, idx2);
            } 
            else if (cmp->left->type == DATA_TYPE_PREFIX || cmp->left->type == DATA_TYPE_NAME) {
                idx = sql_find_table_index_in_rec(rec, cmp->left);
                sql_save_cmp_for_tbl_in_rec(rec, cmp, lgcType, idx);
            }
            else if (cmp->right->type == DATA_TYPE_PREFIX || cmp->right->type == DATA_TYPE_NAME) {
                idx = sql_find_table_index_in_rec(rec, cmp->right);
                sql_save_cmp_for_tbl_in_rec(rec, cmp, lgcType, idx);
            }
        }
        else if (exprList->type == EXPR_TYPE_LOGIC) {
            logic_node_t *logic = (logic_node_t *)exprList->expr_info;
            rec->lgcOp = logic->type;
            sql_sel_collect_qual(rec, logic->left, lgcType);
            sql_sel_collect_qual(rec, logic->right, logic->type);
        }
    }
}

cmp_eval_t *sql_get_cmp_node(cmp_eval_t **cmpEval)
{
    cmp_eval_t *cmpE = *cmpEval;
    *cmpEval = cmpE->next;
    return cmpE;
}

cmp_eval_t *sql_get_cmp_from_table(sel_rec_t *rec, int idx)
{
    cmp_eval_t *cmpE = NULL;
    if(idx >= 0)
        cmpE = rec->cmpForTbl[idx].head;
    return cmpE;
}

var_node_t *sql_get_var_from_eval(cmp_eval_t *cmpEval)
{
    comparison_node_t *cmp = cmpEval->cmp;
    var_node_t *cmpR = cmp->right;
    return cmpR;
}

char *sql_get_attr_from_eval(cmp_eval_t *cmpEval)
{
    comparison_node_t *cmp = cmpEval->cmp;
    var_node_t *cmpL = cmp->left;
    return cmpL->varchar_value; 
}

bool sql_sel_qualifier(sel_rec_t *rec, cmp_eval_t *cmpEval, tuple_t *tuple)
{
    if (!cmpEval) return true;
    comparison_node_t *cmp = cmpEval->cmp;
    var_node_t *cmpL = cmp->left;
    bool result = false;
    attr_node_t *attrNd = tuple->find_attr_vals(tuple, cmpL->varchar_value);
    if (attrNd) {
        if (attrNd->header->data_type == cmp->right->type) {
            switch (cmp->type) {
                case CMP_TYPE_LESS:
                    if (cmp->right->type == DATA_TYPE_INT)
                       result =  (attrNd->value->int_value < cmp->right->int_value);
                    else
                        printf("not allowed type for cmp operator: LESS\n");
                    break;
                case CMP_TYPE_GREATER:
                    if (cmp->right->type == DATA_TYPE_INT)
                       result =  (attrNd->value->int_value > cmp->right->int_value);
                    else
                        printf("not allowed type for cmp operator: GREATER\n");
                    break;
                case CMP_TYPE_EQUAL:
                    if (cmp->right->type == DATA_TYPE_INT)
                       result =  (attrNd->value->int_value == cmp->right->int_value);
                    else if (cmp->right->type == DATA_TYPE_VARCHAR)
                        result = (strcmp(attrNd->value->varchar_value, cmp->right->varchar_value) == 0);
                    else
                        printf("not allowed type for cmp operator: EQUAL\n");
                    break;
                case CMP_TYPE_NOTEQUAL:
                    if (cmp->right->type == DATA_TYPE_INT)
                       result =  (attrNd->value->int_value != cmp->right->int_value);
                    else if (cmp->right->type == DATA_TYPE_VARCHAR)
                        result = (strcmp(attrNd->value->varchar_value, cmp->right->varchar_value) != 0);
                    else
                        printf("not allowed type for cmp operator: EQUAL\n");
                    break;

                default:
                    printf("unexpected cmp type\n");
                    //ERROR
                    break;
            }
            if (cmpEval->next) {
                if (result) {
                    switch (cmpEval->next->type)
                    {
                        case LGC_TYPE_AND:
                            result = (result && sql_sel_qualifier(rec, cmpEval->next, tuple));
                            break;
                        case LGC_TYPE_OR:
                            //printf("LGC_TYPE_OR\n");
                            break;
                        case LGC_TYPE_INVALID:
                            printf("LGC_TYPE_INVALID\n");
                        default:
                            result = false;
                            break;
                    }
                } else {
                    switch (cmpEval->next->type)
                    {
                        case LGC_TYPE_AND:
                            //printf("LGC_TYPE_AND\n");
                            
                            break;
                        case LGC_TYPE_OR:
                            result = (result || sql_sel_qualifier(rec, cmpEval->next, tuple));
                            //printf("LGC_TYPE_OR\n");
                            break;
                        case LGC_TYPE_INVALID:
                            printf("LGC_TYPE_INVALID\n");
                        default:
                            result = false;
                            break;
                    }
                }
            }
        } else {
            // ERROR
        }
    } else {
        // ERROR
    }
    return result;
}

bool sql_sel_compare_attr(cmp_type_e cmpType, attr_node_t *attrL, attr_node_t *attrR)
{
    bool result = false;
    if (attrL->header->data_type == attrR->header->data_type) {
        switch (cmpType) 
        {
            case CMP_TYPE_EQUAL:
                if(attrL->header->data_type == DATA_TYPE_INT)
                    result = (attrL->value->int_value == attrR->value->int_value);
                else if (attrL->header->data_type == DATA_TYPE_VARCHAR)
                    result = (strcmp(attrL->value->varchar_value, attrR->value->varchar_value) == 0);
                else
                    printf("unexpected type\n");
                break;
            case CMP_TYPE_LESS:
                if(attrL->header->data_type == DATA_TYPE_INT)
                    result = (attrL->value->int_value < attrR->value->int_value);
                else
                    printf("unexpected type\n");
                break;
            case CMP_TYPE_GREATER:
                if(attrL->header->data_type == DATA_TYPE_INT)
                    result = (attrL->value->int_value > attrR->value->int_value);
                else
                    printf("unexpected type\n");
                break;
            case CMP_TYPE_NOTEQUAL:
                if(attrL->header->data_type == DATA_TYPE_INT)
                    result = (attrL->value->int_value != attrR->value->int_value);
                else if (attrL->header->data_type == DATA_TYPE_VARCHAR)
                    result = (strcmp(attrL->value->varchar_value, attrR->value->varchar_value) != 0);
                else
                    printf("unexpected type\n");
                break;
            default:
                printf("unexpected cmp type\n");
                break;        
        }
    } else {
        printf("data type not match\n");
    }
    return result;
}

bool sql_sel_qualifier_join(sel_rec_t *rec, cmp_eval_t *cmpEval, tuple_cnn_t *tplCnn)
{
    var_node_t *cmpThis  = NULL;
    tuple_t *tuplePrev = tplCnn->tuple;
    tuple_cnn_t * tplCnnThis = NULL;
    bool result = false;
    int idx = -1;
    comparison_node_t *cmp;
    var_node_t *cmpL = NULL;
    var_node_t *cmpR = NULL;
    attr_node_t *attrPrev = NULL;
    if (cmpEval) {
        cmp = cmpEval->cmp;
        cmpL = cmp->left;
        cmpR = cmp->right;
        if (strcmp(tplCnn->table->name, cmpL->prefix_value) == 0 ) {
            attrPrev= tuplePrev->find_attr_vals(tuplePrev, cmpL->varchar_value);
            idx = cmpEval->cmpR_tblIdx;
            cmpThis = cmpR;
        } else {
            attrPrev= tuplePrev->find_attr_vals(tuplePrev, cmpR->varchar_value);
            idx = cmpEval->cmpL_tblIdx;
            cmpThis = cmpL;
        }
    }
    
        cmp_eval_t *cmpEvalTbl = sql_get_cmp_from_table(rec, idx);
        result = (cmpEvalTbl == NULL);
        table_node_t *table = rec->table[rec->tableRec];// hardcode
        tuple_t *tuple = table->tuple_list_head;
        bool evalTwo = ((cmpEval!=NULL)&&(cmpEvalTbl!=NULL));
        attr_node_t *attrThis = NULL;
        int i;
        int qualTupleNum = 0;
        for (i = 0; i < table->tuple_num; i++) {
            if(cmpThis)
                attrThis = tuple->find_attr_vals(tuple, cmpThis->varchar_value);
            result = (result || sql_sel_qualifier(rec, cmpEvalTbl, tuple));

            if (evalTwo) {
                switch(rec->lgcOp)
                {
                    case LGC_TYPE_OR:
                        result = result || sql_sel_compare_attr(cmpEval->cmp->type, attrPrev, attrThis);
                        break;
                    case LGC_TYPE_AND:
                        result = result && sql_sel_compare_attr(cmpEval->cmp->type, attrPrev, attrThis);
                        break;
                    default:
                        printf("unexpected lgcOp\n");
                        break;
                }
            } else {
            
                result = result && ((cmpEval == NULL)||(sql_sel_compare_attr(cmpEval->cmp->type, attrPrev, attrThis)));
            }
            if (result) {
                qualTupleNum++;
                tplCnnThis = CALLOC_MEM(tuple_cnn_t, 1);
                CALLOC_CHK(tplCnnThis);
                tplCnnThis->table = table;
                tplCnnThis->tuple = tuple;
                if (!tplCnn->nextRel){
                    tplCnn->nextRel = tplCnnThis;
                    tplCnnThis->prevRel = tplCnn;
                    tplCnn->siblHead = tplCnnThis;
                    tplCnn->siblTail = tplCnnThis;
                } else {
                    tplCnn->siblTail->siblNext = tplCnnThis;
                    tplCnnThis->siblPrev = tplCnn->siblTail;
                    tplCnn->siblTail = tplCnnThis;
                }
            }
            tuple = tuple->next;
        }
        tplCnn->nextQualNum = qualTupleNum;
    return (tplCnn->nextRel != NULL);
}


void sql_save_qual_tuple(sel_rec_t *rec, tuple_cnn_t *tplCnn)
{
    if (!rec->head) {
        rec->head = tplCnn;
        rec->tail = tplCnn;
    } else {
        rec->tail->next = tplCnn;
        rec->tail = tplCnn;
    }
    if (tplCnn->nextQualNum)
        rec->tupleNum += tplCnn->nextQualNum;
    else 
        rec->tupleNum++;
}

  // before entering this func, we should check if WHERE clause exist or not 
void sql_sel_stmt_qual_tuple(sel_rec_t *rec)
{
    if (rec->tableRec < rec->tableNum) {
        int tblIdx = rec->tableRec;
        table_node_t *table = rec->table[tblIdx];
        tuple_t *tuple = table->tuple_list_head;
        cmp_eval_t *cmpEval = sql_get_cmp_from_table(rec, tblIdx);
        cmp_eval_t *cmpJoin = rec->cmpJoin;//sql_get_cmp_node(&rec->cmpJoin);
        tuple_cnn_t *tplCnn = CALLOC_MEM(tuple_cnn_t, 1);
        CALLOC_CHK(tplCnn);
        tplCnn->table = table;
        int i;
        rec->tableRec++;
        for (i = 0; i < table->tuple_num; i++) {
            tplCnn->tuple = tuple;
            bool result = ((cmpEval == NULL) || (sql_sel_qualifier(rec, cmpEval, tuple)));
            if ( rec->tableRec < rec->tableNum) {
                if (cmpJoin && (rec->lgcOp != LGC_TYPE_INVALID)) {
                    switch (rec->lgcOp)
                    {
                        case LGC_TYPE_OR:
                            result = (result || sql_sel_qualifier_join(rec, cmpJoin, tplCnn));
                            break;
                        case LGC_TYPE_AND:
                        case LGC_TYPE_INVALID:
                            result = (result && sql_sel_qualifier_join(rec, cmpJoin, tplCnn));
                            break;
                        default:
                            printf("unexpected lgc type\n");
                    }
                } else {
            
                        result = (result && sql_sel_qualifier_join(rec, cmpJoin, tplCnn));
                }
            }
            if (result) {
                sql_save_qual_tuple(rec, tplCnn);
                if (i < (table->tuple_num - 1)) {
                    tplCnn = CALLOC_MEM(tuple_cnn_t, 1);
                    CALLOC_CHK(tplCnn);
                    tplCnn->table = table;
                }
            } else {
                if (i == (table->tuple_num - 1))
                    free(tplCnn);
            }
            tuple = tuple->next;
        }
    }
}

tuple_t *sql_sel_create_qual_tuple_for_output(int tplNum)
{
    int i;
    tuple_t *tupleHead = NULL;
    tuple_t **p_tuple = &tupleHead; 
    for (i = 0; i < tplNum; i++) {
        *p_tuple = sql_tuple_create_and_init();
        p_tuple = &((*p_tuple)->next);
    }
    return tupleHead;
}

attr_node_header_t *sql_look_for_attrHead(sel_rec_t *rec, sel_attr_t *attr, int *idx)
{
    if (attr->table_Name && attr->attr_Name) {
        int i;
        for (i = 0; i < rec->tableNum; i++) {
            if (strcasecmp(rec->table[i]->name, attr->table_Name) == 0) {
                *idx = i;
                return rec->table[i]->find_attr(rec->table[i], attr->attr_Name);
            }
        }
    }
    return NULL;
}

void sql_attr_node_header_cpy(attr_node_header_t *dst, attr_node_header_t *src)
{
    dst->data_type = src->data_type;
    dst->varchar_len = src->varchar_len;
    dst->col_attr = src->col_attr;
}

typedef  int (*aggrFunc)(int *accum, int new);

void sql_transl_to_tbl_traverse_for_aggr(sel_rec_t *rec, char *tblInName, attr_node_header_t *attrHd, char* attrName, attr_node_header_t *attrHdSrc, table_node_t *tblOut, aggregation_type_e  aggreType, bool isPrintAll)
{
        tuple_t *tupleAdd = tblOut->tuple_list_head;
        int tupleNum = rec->tupleNum;
        attr_node_t *attrNd = NULL;
        tuple_t *tupleTgt = NULL;
        attr_node_value_t *attrVal = NULL;
        attr_node_value_t *attrValAggr = NULL;
        int aggrValue = 0 ;
        int tblIdx = -1;
        int repNum = 0;
        bool isRep = false;
        bool isPass = false;
        data_type_e dataType;

        if (isPrintAll) {
            aggrValue = rec->tupleNum;
            isPass = true;
            goto GEN_TUPLE;
        }
        if (attrHdSrc)
            dataType = attrHdSrc->data_type;
        tuple_cnn_t *tupleRec = rec->head;
        tuple_cnn_t *tupleDeep = rec->head;
        while (tupleDeep) {
            if (strcasecmp(tupleDeep->table->name, tblInName) == 0){
                break;
            }
            tupleDeep = tupleDeep->nextRel;
        }
        if (tupleDeep) {
            isRep = (tupleDeep->nextQualNum > 0);
            repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;// should be previos level node
            if (isRep) {
                tupleTgt = tupleDeep->tuple;   
                attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
            }
        }
        while (tupleNum > 0) {
            tupleNum--;
            if (repNum == 0) {
                tupleRec = tupleRec->next;
                tupleDeep = tupleRec;
                while (tupleDeep) {
                    if (strcasecmp(tupleDeep->table->name, tblInName) == 0){
                        break;
                    }
                    tupleDeep = tupleDeep->nextRel;
                }
                repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;
                if (isRep) {
                    tupleTgt = tupleDeep->tuple;   
                    attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
                }
            }
            if (!isRep) {
                tupleTgt = tupleDeep->tuple;
                attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
                tupleDeep = tupleDeep->siblNext;
            }
            if (aggreType == AGGR_TYPE_COUNT) {
                if (attrVal) {//NULL value  can't be count
                    aggrValue++;
                    isPass = true;
                }
            } else if (aggreType == AGGR_TYPE_SUM) {
                if (dataType == DATA_TYPE_INT) {
                    aggrValue+=attrVal->int_value;
                    isPass  = true;
                }
                else
                    printf("not support aggr sum for this type\n");
            }
            //tupleAdd->add_attr_vals(tupleAdd, attrNd);
            //tupleAdd = tupleAdd->next;
            repNum--;
        }

GEN_TUPLE:
        if (isPass) {
            attrNd = CALLOC_MEM(attr_node_t, 1);
            CALLOC_CHK(attrNd);
            attrValAggr = CALLOC_MEM(attr_node_value_t, 1);
            CALLOC_CHK(attrValAggr);
            attrValAggr->int_value = aggrValue;
            attrNd->header = attrHd;
            attrNd->value = attrValAggr;
            tblOut->attr[tblOut->attr_num] = attrHd;
            tblOut->attr_num++;
            tupleAdd->add_attr_vals(tupleAdd, attrNd);
        }
}
void sql_transl_to_tbl_traverse(sel_rec_t *rec, char *tblInName, attr_node_header_t *attrHd, char* attrName, table_node_t *tblOut)
{
        tuple_t *tupleAdd = tblOut->tuple_list_head;
        attr_node_t *attrNd = NULL;
        tuple_t *tupleTgt = NULL;
        attr_node_value_t *attrVal = NULL;
        int tblIdx = -1;
        int repNum = 0;
        bool isRep = false;

        tuple_cnn_t *tupleRec = rec->head;
        tuple_cnn_t *tupleDeep = tupleRec;;
        while (tupleDeep) {
            if (strcasecmp(tupleDeep->table->name, tblInName) == 0){
                break;
            }
            tupleDeep = tupleDeep->nextRel;
            if (!tupleDeep->nextRel) break;
        }
        if (tupleDeep) {
            isRep = (tupleDeep->nextQualNum > 0);
            repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;// should be previos level node
            if (isRep) {
                tupleTgt = tupleDeep->tuple;   
                attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
            }
        }
        while (tupleAdd) {
    
            if (repNum == 0) {
                tupleRec = tupleRec->next;
                tupleDeep = tupleRec;
                while (tupleDeep) {
                    if (strcasecmp(tupleDeep->table->name, tblInName) == 0){
                        break;
                    }
                    if (!tupleDeep->nextRel) break;
                    
                    tupleDeep = tupleDeep->nextRel;
                }
                repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;
                if (isRep) {
                    tupleTgt = tupleDeep->tuple;   
                    attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
                }
            }
            if (!isRep) {
                tupleTgt = tupleDeep->tuple;
                attrVal = (tupleTgt->find_attr_vals(tupleTgt, attrName))->value;
                tupleDeep = tupleDeep->siblNext;
            }
            attrNd = CALLOC_MEM(attr_node_t, 1);
            CALLOC_CHK(attrNd);
            attrNd->header = attrHd;
            attrNd->value = attrVal;
            tupleAdd->add_attr_vals(tupleAdd, attrNd);
            tupleAdd = tupleAdd->next;
            repNum--;
        }

}

void sql_sel_print_all_attr(sel_rec_t *rec, table_node_t *tblIn, char *alias, table_node_t *tblOut)
{
    int i;
    attr_node_header_t *attrHd, *attrHdDst;
    for (i = 0; i < tblIn->attr_num; i++) {
        attrHd = tblIn->attr[i];
        attrHdDst = CALLOC_MEM(attr_node_header_t, 1);
        CALLOC_CHK(attrHdDst);
        sql_attr_node_header_cpy(attrHdDst, attrHd);
        if (alias) {
            char *atrName = CALLOC_MEM(char, strlen(attrHd->name)+strlen(alias)+2);
            CALLOC_CHK(atrName);
            sprintf(atrName,"%s.%s",alias, attrHd->name);
            attrHdDst->name = atrName;
        }
        else
            attrHdDst->name = strdup(attrHd->name);
        
        tblOut->attr[tblOut->attr_num] = attrHdDst;
        sql_transl_to_tbl_traverse(rec, tblIn->name, attrHdDst, attrHd->name, tblOut);
        tblOut->attr_num++;
    }
}

void sql_transl_to_tbl(sel_rec_t *rec, table_node_t *tbl)
{
    sel_attr_t *sAttr = rec->attr_list;
    int i = 0;
    int tblIdx = -1;
    tbl->name = strdup("tmp");
    attr_node_header_t *attrHdDst, *attrHdSrc;
    while (sAttr) {
        
        if (sAttr->isPrintAll && sAttr->isAggregation == 0 ) {
            if (sAttr->table_Name) {
                //char *alias = sql_sel_find_alias_name(rec, sAttr->table_Name);
                char *alias = sAttr->output_Name;
                for (int j = 0; j < rec->tableNum; j++) {
                    if (strcmp(rec->table[j]->name, sAttr->table_Name) == 0)
                        sql_sel_print_all_attr(rec, rec->table[j], alias ,tbl);
                }
            } else {
                for (int j = 0; j < rec->tableNum; j++) {
                    sql_sel_print_all_attr(rec, rec->table[j], NULL, tbl);
                }
            }
            tbl->tuple_num = rec->tupleNum;
        } else if (sAttr->isAggregation > 0) {
            attrHdDst = sql_create_attr(sAttr->output_Name, DATA_TYPE_INT, 0);
            attrHdSrc = sql_look_for_attrHead(rec, sAttr, &tblIdx);
            sql_transl_to_tbl_traverse_for_aggr(rec, sAttr->table_Name, attrHdDst, sAttr->attr_Name, attrHdSrc, tbl, sAttr->isAggregation, sAttr->isPrintAll);
            tbl->tuple_num++;
        } else {

            attrHdSrc = sql_look_for_attrHead(rec, sAttr, &tblIdx);
            attrHdDst = CALLOC_MEM(attr_node_header_t, 1);
            CALLOC_CHK(attrHdDst);
            sql_attr_node_header_cpy(attrHdDst, attrHdSrc);
            attrHdDst->name = strdup(sAttr->output_Name);
            tbl->attr[tbl->attr_num] = attrHdDst;
            sql_transl_to_tbl_traverse(rec, sAttr->table_Name, attrHdDst, attrHdSrc->name, tbl);
            tbl->attr_num++;
            tbl->tuple_num = rec->tupleNum;
        }
        sAttr = sAttr->next;
        i++;
    }
}

sel_attr_t *sql_make_sel_attr_node(char *newName, char *tblName, char *attrName, bool isAll, aggregation_type_e isAggr)
{
    sel_attr_t *sAttr = CALLOC_MEM(sel_attr_t, 1);
    CALLOC_CHK(sAttr);

    if (newName)
        sAttr->output_Name = strdup(newName);
    if (tblName)
        sAttr->table_Name = strdup(tblName);
    if (attrName)
        sAttr->attr_Name = strdup(attrName);
    sAttr->isPrintAll = isAll;
    sAttr->isAggregation = isAggr;
    return sAttr;
}

void sql_sel_temp_select_list_collect(sel_rec_t *rec)
{ 
    char *selecTest[][3] = {
        {"SUM(pages)", "Book", "pages"},//title
    };
    int num = sizeof(selecTest) / sizeof(selecTest[0]);
    int i;
    sel_attr_t *sAttr;
    sel_attr_t **p_sAttr = &sAttr;
    for (i = 0; i < num; i++) {
        *p_sAttr = sql_make_sel_attr_node(selecTest[i][0],
                                          selecTest[i][1],
                                          selecTest[i][2], false, 2);
        p_sAttr = &((*p_sAttr)->next);
    }
    rec->attr_list = sAttr;
}
bool sql_select_tuple_partial_free(tuple_t *tpl)
{
    if (!tpl) return true;
    sql_select_tuple_partial_free(tpl->next);
    attr_node_t *attrNdHd;
    attr_node_t *attrNext;
    for (int i = 0; i <MAX_TUPLE_ATTR_HASH_SIZE; i++) {
        if (tpl->attr[i]) {
            attrNdHd = tpl->attr[i];
            while (attrNdHd) {
                attrNext = attrNdHd->next;
                free(attrNdHd);
                attrNdHd = attrNext;
            }
        }
    }
    return false;
}
bool sql_select_tuple_all_free(tuple_t *tpl)
{
    if (!tpl) return true;
    sql_select_tuple_all_free(tpl->next);
    attr_node_t *attrNdHd;
    attr_node_t *attrNext;
    for (int i = 0; i <MAX_TUPLE_ATTR_HASH_SIZE; i++) {
        if (tpl->attr[i]) {
            attrNdHd = tpl->attr[i];
            while (attrNdHd) {
                attrNext = attrNdHd->next;
                free(attrNdHd->value);
                free(attrNdHd);
                attrNdHd = attrNext;
            }
        }
    }
    return false;
}
void sql_select_vrt_table_free(sel_rec_t *rec, table_node_t *tbl)
{
    sql_select_tuple_partial_free(tbl->tuple_list_head);
    for (int i = 0; i < tbl->attr_num; i++) {
        if (tbl->attr[i]) {
            free(tbl->attr[i]->name);
            free(tbl->attr[i]);
        }
    }
    free(tbl->name);
}

bool sql_select_stmt_handle(select_stmt_t *selStmt)
{
    /*Refered to sql_show_table_content() */
    /*Decode "From" instruction to get the table to use and construct an aliases-table.*/
    /*Decode "Where" instruction*/
    /*Decode "Select" instruction*/
        /*check whether it is aggregation function for every col_node. */
    table_node_t tbl;
    sel_rec_t rec;
    FILE *slog = fopen(SELECT_LOG, "w");
    fprintf(slog, "***start log ***\n");
    fclose(slog);
    memset(&rec, 0, sizeof(sel_rec_t));
    memset(&tbl, 0, sizeof(table_node_t));
    rec.lgcOp = LGC_TYPE_INVALID;
    sql_sel_collect_table(&rec, selStmt->select_table_list);
    if( sql_select_errchk(&rec, selStmt) ) {
        printf("Select statement error\n");
        return true; 
    }
    else {
        printf("Start select:\n");
    }
    sql_sel_collect_attr(&rec, selStmt->select_col_list);
    sql_sel_collect_qual(&rec, selStmt->select_qualifier, LGC_TYPE_INVALID);
    sql_sel_qual_start(&rec);
    //sql_sel_stmt_qual_tuple(&rec);
    tuple_t *tupleHead = sql_sel_create_qual_tuple_for_output(rec.tupleNum);
    tbl.tuple_list_head = tupleHead;
    sql_transl_to_tbl(&rec, &tbl);
    sql_print_table(&tbl);
    sql_select_vrt_table_free(&rec, &tbl);
    sql_select_record_free(&rec);
    return true;   
}



stmt_node_t *sql_import_file(char *name, char *lastName)
{
    FILE *import;
    extern FILE *yyin;
    char fileName[MAX_IMPORT_FILE_NAME_LENGTH];
    if (strlen(name) < (MAX_IMPORT_FILE_NAME_LENGTH-4))
        strcpy(fileName, name);
    sprintf(fileName, "%s.%s",fileName, lastName);
    //strcat(fileName,lastName);
    printf("import file %s\n", fileName);
    import = fopen(fileName, "r");
    if (import) {
        yyin = import;
    } else {
        printf("file:%s does not exist\n", fileName);
    }
    stmt_node_t *stmt = sql_stmt_act_init();
    sql_stmt_save(stmt, STMT_TYPE_IMPORT_FILE, NULL);
    return stmt;
}

expr_node_t *sql_expr_aggregation_node_create(aggregation_type_e type, bool is_star, expr_node_t *expr_node)
{
    /*Error condition*/
    if (is_star == false && (expr_node == NULL || expr_node->expr_info == NULL || expr_node->type != EXPR_TYPE_BASIC_VAR)){
        printf("\nError: \"expr_node\" error in sql_expr_aggregation_node_create().\n");
        return NULL;
    }
    
    /*Countruct aggr_node*/
    aggregation_node_t *aggregation_node = CALLOC_MEM(aggregation_node_t, 1);
    CALLOC_CHK(aggregation_node);
    aggregation_node->type = type;
    aggregation_node->is_star = is_star;
    if(is_star)
        aggregation_node->attr_info = NULL;
    else
        aggregation_node->attr_info = expr_node->expr_info;
    
    /*Countruct expr_node*/
    expr_node_t *new_expr_node = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(new_expr_node);
    new_expr_node->type = EXPR_TYPE_AGGREGATION;
    new_expr_node->expr_info = (void *)aggregation_node;
    return new_expr_node;
}

void sql_recover_table_info_tuple(table_node_t *tbl)
{
    uint32_t tupleNum;
    uint16_t offset, pageOffset, pageNum;
    char *page; 
    int i;
    tuple_t *tuple;
    pageNum = ntohl(*(uint32_t *)(tbl->pageTable[0].page + DB_PAGE_HEADER_SIZE));
    tupleNum = 0;

    for (i = 1; i < pageNum; i++) {
        offset = DB_PAGE_HEADER_SIZE;
        page = tbl->pageTable[i].page;    
        pageOffset = *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_OFFSET);
        while (offset < pageOffset) {
            tuple = sql_tuple_create_and_init();
            tuple->pageId = i;
            tuple->offset = offset;
            printf("(%d, %d)\n", i, offset);
            db__page_tuple_info_unpacked(tbl, tuple, &offset, page);
            tbl->add_tuple(tbl, tuple);
            tupleNum++;
        }
    }
    //for test
    //if (tbl->find_attr(tbl, "userid") && strcmp(tbl->name, "user1")==0 )
    //    sql_set_table_idx_tree(&db_tree, tbl, "userid");
    assert(tupleNum == tbl->tuple_num);
}

static void sql_recover_table_info_pkey(table_node_t *tbl)
{
    int i;
    for (i = 0; i < tbl->attr_num; i++) {
        if (tbl->attr[i]->col_attr & ATTR_PRIKEY) {
            tbl->add_prikey_attr(tbl, tbl->attr[i]);
        }       
    }
}

static void sql_recover_table_info(db_db_t *db)
{
    char *tblName;
    table_node_t *tbl;
    int i;


    for (i = 0; i < db->tbl_num; i++) {
        tblName = strdup(db->tbl[i].name);
        tbl = sql_cret_tbl_table_create_and_init(tblName);
        db__table_info_create(tbl);
        db__table_info_read(tbl);
        sql_recover_table_info_pkey(tbl);
        sql_cret_tbl_add_table(tbl);
        db__table_info_all_pages_read(tbl);
        sql_recover_table_info_tuple(tbl);
        //sql_print_table(tbl);
        //for test
    }

    // test
 /*   
    char *value;
    char key[64];
    sprintf(key, "%d", 20);
    if (db__tree_idx_gets(&db_tree, key, &value) != BP_OK)
        printf("get fails\n");
    else
        printf("tuple address: %s\n", value);
    tuple_t *tuple;
    //sql_idx_get_tuple(&db_tree, tbl, DATA_TYPE_INT, 20, NULL, &tuple);
    var_node_t v1, v2;
    v1.type = DATA_TYPE_INT;
    v2.type = DATA_TYPE_INT;
    v1.int_value = 9989;
    v2.int_value = 9999;
    sql_idx_get_tuple_range(&db_tree, tbl, &v1, &v2, &tuple);
*/
}

//int sql_idx_get_tuple_range(bp_db_t *db, table_node_t *tbl, var_node_t *start, var_node_t *end, tuple_t **tupleOut)
//int sql_idx_get_tuple(bp_db_t *db, table_node_t *tbl, data_type_e dataType, int int_value, char *varchar_value, tuple_t **tupleOut)
void sql_gen_key_string(attr_node_t *attr, char *key)
{
    if (attr->header->data_type == DATA_TYPE_INT) {
        sprintf(key, "%d", attr->value->int_value);
    } else {
        strcpy(key, attr->value->varchar_value);
    }
}

int sql_set_table_idx_tree(bp_db_t *db, table_node_t *tbl, col_node_t *col_list)
{
    char fileName[128];
    char attrName[128]="";
    char key[128]="";
    char attrStr[64];
    char *value = malloc(64);
    tuple_t *tuple = tbl->tuple_list_head;
    attr_node_t *attr = NULL;
    attr_node_header_t *attrHd = NULL;
    col_node_t *col = col_list;
    int ret;
    while (col) {
        attrHd = tbl->find_attr(tbl, (char *)col->name);
        if (attrHd) {
            strcat(attrName, col->name);
        } else {
            printf("fail to find all the ATTR In col_list\n");
            return -1;
        }
        col = col->next;
    }
    sprintf(fileName, "%s_%s_tree.idx", tbl->name, attrName);
    ret = db__tree_idx_create(db, fileName);
    if (attrHd->data_type == DATA_TYPE_INT)
        db__tree_set_num_compare_cb(db);
    if (ret != BP_OK) return ret;
    while (tuple) {
        col = col_list;
        sprintf(value, ",%d_%d", tuple->pageId, tuple->offset);        
        while (col) {
            attr = tuple->find_attr_vals(tuple, (char *)col->name);
            if (attr) {
                sql_gen_key_string(attr, key);
                strcat(key, attrStr);
            } else {
                strcat(key, "000");
            }
            col = col->next;
        }
        //address can be in-memory addr
        printf("key = %s, value = %s\n", key, value);
        ret = db__tree_idx_sets(db, key, &value);
        if (ret != BP_OK)
            printf("insert(idx) fails => \n\ttable:%s, key:%s, value:%s\n",
                        tbl->name, key, value);
        tuple = tuple->next;
    }
    return ret;
}
// start < TARGET < end
// if start = NULL, comp_type = less than

//0508
int sql_set_table_idx_hash(table_node_t *tbl, col_node_t *col_list){
    char fileName[128];
    char attrName[128]="";
    char key[128]="";
    char attrStr[64];
    unsigned int value;// our hash value type is unsigned int
    tuple_t *tuple = tbl->tuple_list_head;
    attr_node_t *attr = NULL;
    attr_node_header_t *attrHd = NULL;
    col_node_t *col = col_list;
    int ret;
    while (col) {
        attrHd = tbl->find_attr(tbl, (char *)col->name);
        if (attrHd) {
            strcat(attrName, col->name);
        } else {
            printf("fail to find all the ATTR In col_list\n");
            return -1;
        }
        col = col->next;
    }
    sprintf(fileName, "%s_%s_hash.idx", tbl->name, attrName);
    ret = db__hash_idx_craete(fileName);// create hash index
    
        
    if (ret != EH_OK) return ret;
   
    while (tuple) {
        
        col = col_list;
        value = tuple->pageId*10000+tuple->offset;// value format = pageId*10000+offset
        while (col) {
            attr = tuple->find_attr_vals(tuple, (char *)col->name);
            if (attr) {
                sql_gen_key_string(attr, key);
                //strcat(key, attrStr);//??
            } else {
                //strcat(key, "000");
            }
            col = col->next;
        }
        //address can be in-memory addr
        printf("key = %s, value = %d\n", key, value);
        ret = db__hash_idx_sets(fileName, key, value);//hashIdx.c set function
        if (ret != EH_OK)
            printf("insert to hash idx fails => \n\ttable:%s, key:%s, value:%d\n",
                        tbl->name, key, value);
        tuple = tuple->next;
    }

    return ret;
}
//0508

int sql_idx_get_tuple_range(bp_db_t *db, table_node_t *tbl, var_node_t *start, var_node_t *end, tuple_t **tupleOut)
{
    data_type_e dataType;
    tree_range_t r;
    r.qual_num = 0;
    char *delim = ",";
    char *output;
    char *page;
    char *value;
    uint16_t pageId, offset;
    tuple_t *tuple;
    table_node_t *tmpTbl = sql_cret_tbl_table_create_and_init("tmpInFunc");
    int ret, i;

    if (start)
        dataType = start->type;
    if (end)
        assert(dataType == end->type);

    if (dataType == DATA_TYPE_INT) {
        char key1[64];
        char key2[64];
        sprintf(key1, "%d", start->int_value);
        sprintf(key2, "%d", end->int_value);
        ret = db__tree_idx_get_range(db, key1, key2, (void *)&r);
    } else {
        ret = db__tree_idx_get_range(db, start->varchar_value, end->varchar_value, (void *)&r);
    }
    
    if (ret != BP_OK) {
        printf("fail in idx get tuple\n");
        return ret;
    }

    for (i = 0; i < r.qual_num; i++) {
        
        value = r.addr[i];
        if (value && (ret == BP_OK)) {
            output = strtok(value, delim);

            while (output != NULL) {
                printf("%s\n",value);
                sscanf(output, "%hd_%hd", &pageId, &offset);
        
                if (tbl->pageTable[pageId].valid_bit == 0) {
                    ret = db__table_info_page_fault_hdl(tbl, pageId, (char **)&page);
                } else {
                    page = tbl->pageTable[pageId].page;
                }
                tuple = sql_tuple_create_and_init();
                tuple->pageId = pageId;
                tuple->offset = offset;
                db__page_tuple_info_unpacked(tbl, tuple, &offset, page);
                tmpTbl->add_tuple(tmpTbl, tuple);
                output = strtok(NULL, delim);
            }
        }
        free(value);
    }
    if (ret!=BP_OK) {
        tuple = tmpTbl->tuple_list_head;
        tuple_t *tmpTuple;
        while (tuple) {
            tmpTuple = tuple->next;
            free(tuple);
            tuple = tmpTuple;
        }
        goto fatal;
    }
    *tupleOut = tmpTbl->tuple_list_head;
fatal:
    free(tmpTbl);
    return ret;
}


int sql_idx_get_tuple(bp_db_t *db, table_node_t *tbl, var_node_t *v, tuple_t **tupleOut)
{
    char *value;
    char *delim = ",";
    char *output;
    char *page;
    uint16_t pageId, offset;
    int ret;
    tuple_t *tuple;
    table_node_t *tmpTbl = sql_cret_tbl_table_create_and_init("tmpInFunc");
    data_type_e dataType = v->type;

    if (dataType == DATA_TYPE_INT) {
        char key[64];
        sprintf(key,"%d", v->int_value);
        ret = db__tree_idx_gets(db, key, &value);
    } else {
        ret = db__tree_idx_gets(db, v->varchar_value, &value);
    }
    if (ret != BP_OK) {
        printf("fail in idx get tuple\n");
        free(tmpTbl);
        return ret;
    }
    // note: input: value, tbl
    output = strtok(value, delim);

    while (output != NULL) {
        printf("%s\n",value);
        sscanf(output, "%hd_%hd", &pageId, &offset);
        
        if (tbl->pageTable[pageId].valid_bit == 0) {
            ret = db__table_info_page_fault_hdl(tbl, pageId, (char **)&page);
            if (ret != BP_OK) goto fatal;
        } else {
            page = tbl->pageTable[pageId].page;
        }
        tuple = sql_tuple_create_and_init();
        tuple->pageId = pageId;
        tuple->offset = offset;
        db__page_tuple_info_unpacked(tbl, tuple, &offset, page);
        tmpTbl->add_tuple(tmpTbl, tuple);
        output = strtok(NULL, delim);
    }
    *tupleOut = tmpTbl->tuple_list_head;

fatal:
    free(value);
    free(tmpTbl); 
    return ret;
}


void sql_init()
{
    /* stmt destroy function register*/
    stmt_dstry = CALLOC_MEM(stmt_dstry_func, 20);
    CALLOC_CHK(stmt_dstry);
    stmt_dstry[STMT_TYPE_CREATE_TABLE] = sql_cret_tbl_stmt_destroy;
    stmt_dstry[STMT_TYPE_INSERT_TUPLE] = sql_insr_tpl_stmt_destroy;
    stmt_dstry[STMT_TYPE_CREATE_INDEX] = sql_cret_idx_stmt_destroy;
    stmt_dstry[STMT_TYPE_SELECT_TUPLE] = sql_select_stmt_destroy;
    // test table save
    sql_index_cb[0] = sql_idx_full_scan_cb, //showul be scan
    sql_index_cb[1] = sql_idx_tree_cb, 
    sql_index_cb[2] = sql_idx_tree_cb, 
    sql_index_cb[3] = sql_idx_tree_cb, 
    sql_index_cb[4] = sql_idx_hash_cb,//should be hash 
    
    sprintf(intMAX, "%d", INT_MAX);
    sprintf(intMIN, "%d", INT_MIN);

    db__dbms_info_create(&dbms, "DBSQL");
    if (dbms.tbl_num)    
        sql_recover_table_info(&dbms);
}

//0508 sql_hash_idx_get_tuple
int sql_hash_idx_get_tuple(table_node_t *table, char * attrName, var_node_t* hashKey, tuple_t **tupleOut)
{
    unsigned int *value;
    char fileName[128];
    char key[128];
    if (hashKey->type == DATA_TYPE_INT) {
        sprintf(key, "%d", hashKey->int_value);
    } else {
        strcpy(key, hashKey->varchar_value);
    }
    
    char *page;
    uint16_t pageId, offset;
    int ret;
    tuple_t *tuple;
    table_node_t *tmpTbl = sql_cret_tbl_table_create_and_init("tmpInFunc");
    sprintf(fileName, "%s_%s_hash.idx", table->name, attrName);
    ret = db__hash_idx_gets(fileName, key, &value);
    if(ret == -1){
        printf("Fail in hash idx get tuple\n");
        free(tmpTbl);
        return ret;
    } else if (ret == 0) {
        printf("No Tuple whih the value [ %s ] in the table [%s] : [%s]\n", key, table->name, attrName);
        tupleOut = NULL;
        free(tmpTbl);
        return ret;
    }
    else printf("Get hash tuple succed\n");
    printf("%d Tuples whih the value [ %s ] in the table [%s] : [%s]\n",ret/2 ,key, table->name, attrName);
    int valueSize = ret;
    int i;
    for(i = 0; i < valueSize; i++){
        pageId = value[i];
        i++;
        offset = value[i];
        
        if (table->pageTable[pageId].valid_bit == 0) {
            ret = db__table_info_page_fault_hdl(table, pageId, (char **)&page);
            if (ret != BP_OK) goto fatal;
        } else {
            page = table->pageTable[pageId].page;
        }
        tuple = sql_tuple_create_and_init();
        tuple->pageId = pageId;
        tuple->offset = offset;
        db__page_tuple_info_unpacked(table, tuple, &offset, page);
        tmpTbl->add_tuple(tmpTbl, tuple);
        
    }
    *tupleOut = tmpTbl->tuple_list_head;
fatal:
    free(value);
    free(tmpTbl); 
    return ret;
}


//0508


/**************TEST FUNCTION***************/

#define MAX_TARGET_NUM 1
#define MAX_TABLE_NUM 2

stmt_node_t *sql_sel_stmt_hdl(select_stmt_t *selStmt)
{
    table_node_t tbl;
    sel_rec_t rec;
    memset(&rec, 0, sizeof(sel_rec_t));
    memset(&tbl, 0, sizeof(table_node_t));
    // collect table in rec
    sql_sel_collect_table(&rec, selStmt->select_table_list);
    sql_sel_temp_select_list_collect(&rec);
    rec.lgcOp = LGC_TYPE_INVALID;
    sql_sel_collect_qual(&rec, selStmt->select_qualifier, LGC_TYPE_INVALID);
    sql_sel_stmt_qual_tuple(&rec);
    
    tuple_t *tupleHead = sql_sel_create_qual_tuple_for_output(rec.tupleNum);
    
    //tbl.add_tuple(&tbl, tupleHead);
    tbl.tuple_list_head = tupleHead;
    sql_transl_to_tbl(&rec, &tbl);
    sql_print_table(&tbl);
    // collect where clause and chk ambiguity
    stmt_node_t *stmt = sql_stmt_act_init();
    sql_stmt_save(stmt, STMT_TYPE_TEST_SEL, NULL);
    return stmt;
    
}
comparison_node_t *sql_test_make_cmp_node(cmp_type_e cmp_type, 
                                          data_type_e ltype, 
                                          char *lPfxVal,
                                          char *lvalue, 
                                          data_type_e rtype, 
                                          char *rPfxVal,
                                          int rvalInt,
                                          char *rvalStr)
{

    comparison_node_t *comp = CALLOC_MEM(comparison_node_t, 1);
    CALLOC_CHK(comp);
    var_node_t *varL = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(varL);
    var_node_t *varR = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(varR);
    comp->type = cmp_type;
    comp->left = varL;
    comp->right = varR;
    varL->type = ltype;
    if(ltype == DATA_TYPE_NAME)
        varL->varchar_value = strdup(lvalue);
    else{
        varL->prefix_value = strdup(lPfxVal);
        varL->varchar_value = strdup(lvalue);
    }
    varR->type = rtype;
    if(rtype==DATA_TYPE_INT)
        varR->int_value = rvalInt;
    else if (rtype == DATA_TYPE_VARCHAR || rtype == DATA_TYPE_NAME)
        varR->varchar_value = strdup(rvalStr);
    else {
        varR->prefix_value = strdup(rPfxVal);
        varR->varchar_value = strdup(rvalStr);
    }

    return comp;

}

logic_node_t *sql_test_make_logic_node(expr_node_t *L, expr_node_t *R, lgc_type_e lgcType)
{
    logic_node_t *logic = CALLOC_MEM(logic_node_t, 1);
    CALLOC_CHK(logic);
    logic->type = lgcType;
    logic->left = L;
    logic->right= R;
    return logic;
}

select_stmt_t *sql_test_select()
{
    
    char *test = CALLOC_MEM(char, 100);
    select_stmt_t *select = CALLOC_MEM(select_stmt_t, 1);
    CALLOC_CHK(select);
    char target [MAX_TARGET_NUM][20] = {
        "title"
    };
    char table [][20] = {
        "Book",
        "Author"
    };

    var_node_t * colNd = NULL;
    select_col_node_t * sColNd = NULL;
    select_col_node_t * sColNdHd = NULL;
    colNd = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(colNd);
    sColNd = CALLOC_MEM(select_col_node_t, 1);
    CALLOC_CHK(sColNd);
    sColNdHd = sColNd;
    for (int i = 0; i < MAX_TARGET_NUM; i++)
    {
        colNd->varchar_value = strdup(target[i]);
        sColNd->col_info = colNd;
        if (i<=(MAX_TARGET_NUM-1)){
            colNd = CALLOC_MEM(var_node_t, 1);
            CALLOC_CHK(colNd);
            sColNd->next = CALLOC_MEM(select_col_node_t, 1);
            CALLOC_CHK(sColNd->next);
            sColNd = sColNd->next;
        }
    }
    colNd = NULL;
    select_table_node_t * sTblNd = NULL;
    select_table_node_t * sTblNdHd = NULL;
    colNd = CALLOC_MEM(var_node_t, 1);
    CALLOC_CHK(colNd);
    sTblNd = CALLOC_MEM(select_table_node_t, 1);
    CALLOC_CHK(sTblNd);
    sTblNdHd = sTblNd;
    for (int i = 0; i < MAX_TABLE_NUM; i++)
    {
        colNd->varchar_value = strdup(table[i]);
        sTblNd->table_info = colNd;
        if (i<(MAX_TABLE_NUM-1)){
            colNd = CALLOC_MEM(var_node_t, 1);
            CALLOC_CHK(colNd);
            sTblNd->next = CALLOC_MEM(select_table_node_t, 1);
            CALLOC_CHK(sTblNd->next);
            sTblNd = sTblNd->next;
        }
    }

    expr_node_t * exprL = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(exprL);
    exprL->type = EXPR_TYPE_COMPARISON;
    exprL->expr_info = (void *)sql_test_make_cmp_node(CMP_TYPE_EQUAL, DATA_TYPE_PREFIX, "Book", "authorId", DATA_TYPE_PREFIX, "Author", 0, "authorId"); 
    
    expr_node_t * exprR = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(exprR);
    exprR->type = EXPR_TYPE_COMPARISON;
    exprR->expr_info = (void *)sql_test_make_cmp_node(CMP_TYPE_GREATER, DATA_TYPE_NAME, "Book", "pages", DATA_TYPE_INT, NULL, 200, NULL); 
    
    expr_node_t * expr = CALLOC_MEM(expr_node_t, 1);
    CALLOC_CHK(expr);
    expr->type = EXPR_TYPE_LOGIC;
    expr->expr_info = (void *)sql_test_make_logic_node(exprL, exprR, LGC_TYPE_AND);
    
    select_stmt_t *selStmt = CALLOC_MEM(select_stmt_t, 1);
    CALLOC_CHK(selStmt);
    selStmt->select_col_list = sColNdHd;
    selStmt->select_table_list = sTblNdHd;
    selStmt->select_qualifier = expr;
    return selStmt;
}





bool sql_select_errchk(sel_rec_t *rec, select_stmt_t *selStmt)
{
    bool error = false;
    
    FILE *slog = fopen(SELECT_LOG, "w");

    error = sql_select_tablename_errchk(rec, selStmt->select_table_list);
    if(error) return true;
    else fprintf(slog, "Valid table name\n");
    
    error = sql_select_attrname_errchk(rec, selStmt->select_col_list);
    if(error) return true;
    else fprintf(slog, "Valid attr list\n");
    
    error = sql_select_qulifier_errchk(rec, selStmt->select_qualifier);
    if(error) return true;
    else fprintf(slog,"Valid qulifier\n");
    fclose(slog);
    return error;
}//0410


bool sql_select_tablename_errchk(sel_rec_t *rec, select_table_node_t *table_list){
    // chk if table_name make sense
    bool err_exist = false;
    table_node_t *table1 = NULL;
    table_node_t *table2 = NULL;
    FILE *slog = fopen(SELECT_LOG, "w");
    if(table_list->next == NULL){
        table1 = sql_find_table(table_list->table_info->varchar_value);
        if(table1==NULL){
            printf("\ntable doesn't exist\n");
            err_exist = true;
            fclose(slog);
            return err_exist;
        }
        else{
            fprintf(slog, "\nonly one table\ntable name: %s\n", table1->name);
        }
    }
    else if(table_list->next != NULL){
        table1 = sql_find_table(table_list->table_info->varchar_value);
        table2 = sql_find_table(table_list->next->table_info->varchar_value);
        if(table1==NULL || table2==NULL){
            printf("\ntable doesn't exist\n");
            err_exist = true;
            fclose(slog);
            return err_exist;
        }
        else{
            fprintf(slog,"\nthere are two tables\n");
            fprintf(slog,"table1 name: %s\n", table1->name);
            fprintf(slog,"table2 name: %s\n", table2->name);
        }
    }
    //not yet check if there are two same alias name
    //if err exist, return true
    fclose(slog);
    return err_exist;
}//0410




bool sql_select_qulifier_errchk(sel_rec_t *rec, expr_node_t *select_qualifier){
    if(select_qualifier == NULL) return false;
    bool err_exist = false;
    table_node_t *table1 = NULL;
    table_node_t *table2 = NULL;
    FILE *slog = fopen(SELECT_LOG, "w");
    //select_stmt_t *select_stmt = NULL;
    //select_stmt = stmt_nd->stmt_info;
    table1 = rec->table[0];
    table2 = rec->table[1];
    expr_node_t *expr_node = select_qualifier;
    if(select_qualifier->type==EXPR_TYPE_COMPARISON){
        if(sql_select_cmp_errchk(rec, expr_node)){
            err_exist = true;
            fclose(slog);
            return err_exist;
        }
    }
    else if(select_qualifier->type==EXPR_TYPE_LOGIC){
        fprintf(slog,"\nin logic!\n");
        logic_node_t *select_lgc = expr_node->expr_info;
        expr_node_t *expr_left = select_lgc->left;
        expr_node_t *expr_right = select_lgc->right;
        if(sql_select_cmp_errchk(rec, expr_left)==true){
            printf("\nleft cmp wrong\n");
            err_exist = true;
            fclose(slog);
            return err_exist;
        }
        if(sql_select_cmp_errchk(rec, expr_right)==true){
            printf("\nright cmp wrong\n");
            err_exist = true;
            fclose(slog);
            return err_exist;
        }
        // two cmp
    }
    if(err_exist==false){
        fprintf(slog,"qualifier is right!\n");
    }
    fclose(slog);
    return err_exist;
}



bool sql_select_cmp_errchk(sel_rec_t *rec, expr_node_t * expr_node){
    bool err_exist = false;
    table_node_t *table1 = NULL;
    table_node_t *table2 = NULL;
    //select_stmt_t *select_stmt = NULL;
    //select_stmt = stmt_nd->stmt_info;
    FILE *slog = fopen(SELECT_LOG, "w");
    table1 = rec->table[0];
    table2 = rec->table[1];
    comparison_node_t *comparison_node = expr_node->expr_info;//
    int l_datatype = comparison_node->left->type;
    int r_datatype = comparison_node->right->type;
    fprintf(slog, "left type: %s\n", sql_data_type_translate(comparison_node->left->type));
    fprintf(slog,"right type: %s\n", sql_data_type_translate(comparison_node->right->type));
    
    
    if(comparison_node->left->type==DATA_TYPE_NAME || comparison_node->left->type==DATA_TYPE_PREFIX){
        attr_node_header_t *attr_node1 = NULL;
        attr_node_header_t *attr_node2 = NULL;
        if(sql_select_var_node_errchk(rec, comparison_node->left)){
            err_exist = true;
            printf("Error! left val_node\n");
            fclose(slog);
            return err_exist;
        }
        else{
            if(comparison_node->left->type==DATA_TYPE_NAME){
                attr_node1 = table1->find_attr(table1, comparison_node->left->varchar_value);
                if(table2 != NULL)
                    attr_node2 = table2->find_attr(table2, comparison_node->left->varchar_value);
                if(attr_node1){
                    l_datatype = attr_node1->data_type;
                    fprintf(slog, "attr_node datatype: %s\n", sql_data_type_translate(attr_node1->data_type));
                }
                else{
                    l_datatype = attr_node2->data_type;
                    fprintf(slog, "attr_node datatype: %s\n", sql_data_type_translate(attr_node2->data_type));
                }
            }
            else if(comparison_node->left->type==DATA_TYPE_PREFIX){
                char *table_name = sql_sel_find_tbl_name(rec, comparison_node->left->prefix_value);
                table_node_t* table_nd = sql_find_table(table_name);
                attr_node1 = table_nd->find_attr(table_nd, comparison_node->left->varchar_value);
                l_datatype = attr_node1->data_type;
                fprintf(slog, "attr_node l_datatype: %s\n", sql_data_type_translate(attr_node1->data_type));
            }
        }
    }// deal left, get l_datatype
        
    if(comparison_node->right->type==DATA_TYPE_NAME || comparison_node->right->type==DATA_TYPE_PREFIX){
        attr_node_header_t *attr_node1 = NULL;
        attr_node_header_t *attr_node2 = NULL;
        if(sql_select_var_node_errchk(rec, comparison_node->right)){
            err_exist = true;
            printf("Error! right val_node\n");
            fclose(slog);
            return err_exist;
        }
        else{
            if(comparison_node->left->type==DATA_TYPE_NAME){
                attr_node1 = table1->find_attr(table1, comparison_node->right->varchar_value);
                attr_node2 = table2->find_attr(table2, comparison_node->right->varchar_value);
                if(attr_node1){
                    r_datatype = attr_node1->data_type;
                    //printf("attr_node datatype: %d\n", attr_node1->data_type);
                fprintf(slog, "attr_node datatype: %s\n", sql_data_type_translate(attr_node1->data_type));
                }
                else{
                    r_datatype = attr_node2->data_type;
                    //printf("attr_node datatype: %d\n", attr_node2->data_type);
                fprintf(slog, "attr_node datatype: %s\n", sql_data_type_translate(attr_node2->data_type));
                }
            }
            else if(comparison_node->right->type==DATA_TYPE_PREFIX){
                char *table_name = sql_sel_find_tbl_name(rec, comparison_node->right->prefix_value);
                table_node_t* table_nd = sql_find_table(table_name);
                attr_node1 = table_nd->find_attr(table_nd, comparison_node->right->varchar_value);
                r_datatype = attr_node1->data_type;
                fprintf(slog,"attr_node r_datatype: %s\n", sql_data_type_translate(attr_node1->data_type));
            }
        }
    }// deal right, get r_datatype
    if(l_datatype!=r_datatype){
        err_exist = true;
        fprintf(slog, "\nError! l_datatype != r_datatype\n\n");
        return err_exist;
    }
    else{
        fprintf(slog, "l_datatype = %s\n", sql_data_type_translate(l_datatype));
        fprintf(slog, "r_datatype = %s\n", sql_data_type_translate(r_datatype));
    }
    if(err_exist==false){
        fprintf(slog, "compare is right!\n");
    }
    fclose(slog);
    return err_exist;
}






bool sql_select_attrname_errchk(sel_rec_t *rec, select_col_node_t *attr_chk){
    bool err_exist = false;
    
    while(attr_chk!=NULL){
        if (attr_chk->is_prefix_dot_star){
            sql_select_var_node_errchk(rec, (var_node_t*)attr_chk->col_info);
        }
        else if (!(attr_chk->is_star)){
            
            if (attr_chk->is_aggregation){
                if(!((aggregation_node_t*)attr_chk->col_info)->is_star)
                    if ( sql_select_var_node_errchk(rec, ((aggregation_node_t*)attr_chk->col_info)->attr_info) )
                        return true;
            }
            else{
                if ( sql_select_var_node_errchk(rec, (var_node_t*)attr_chk->col_info) )
                    return true;
            }
            
        }
        attr_chk = attr_chk->next;
    }
    
    //if err exist, return true
    return err_exist;
}//0410

bool sql_select_var_node_errchk(sel_rec_t *rec, var_node_t *var_node)
{
    switch (var_node->type)
    {
        case DATA_TYPE_NAME:
            if( sql_select_data_type_name_errchk(rec, var_node) ){
                printf("Var node: DATA_TYPE_NAME error\n");
                return true;
            }
            break;
        case DATA_TYPE_PREFIX:
            if (sql_select_data_type_prefix_errchk(rec, var_node)){
                printf("Var node: DATA_TYPE_PREFIX error\n");
                return true;
            }
            break;
        case DATA_TYPE_PREFIX_STAR:
            if (sql_select_data_type_prefix_star_errchk(rec, var_node)){
                printf("Var node: DATA_TYPE_PREFIX_STAR error\n");
                return true;
            }
            break;
        default:
            printf("\nError! unknown data type\n");
            return true;
            break;
    }
    return false;
}

bool sql_select_data_type_prefix_star_errchk(sel_rec_t *rec, var_node_t *var_node)
{
    /*Check whether prefix is in one of the two tables*/
    char* tableFound;
        
    if ( (tableFound = sql_sel_find_tbl_name(rec, var_node->prefix_value)) !=NULL ){
        return false;
    }
    else {
        printf("\nError! Table %s was Not Found.\n", var_node->prefix_value);
        return true;
    }
}
bool sql_select_data_type_prefix_errchk(sel_rec_t *rec, var_node_t *var_node)
{
    /*Check whether prefix is in one of the two tables*/
    char* tableFound;
        /*Yes -> chech the prefix'attr is in table or not*/
        /*No -> print erroe message and return*/
    if ( (tableFound = sql_sel_find_tbl_name(rec, var_node->prefix_value)) != NULL ){
        table_node_t* tablePointer =  sql_find_table(tableFound);
        if (tablePointer->find_attr(tablePointer, var_node->varchar_value))
            return false;
        else {
            printf("\nError! attrname: %s doesn't in the table.\n\n", var_node->varchar_value);
            return true;
        }
    }
    else {
        printf("\nError! Table %s was Not Found.\n\n", var_node->prefix_value);
        return true;
    }
}


bool sql_select_data_type_name_errchk(sel_rec_t *rec, var_node_t *var_node)
{
    /*The table2 may be NULL*/
    /*Check that name is exacly in only one table.*/
    int i;
    int tableNumbersWithAttr = 0;
    for(i = 0; i < MAX_SELECT_JOIN_TABLE; i++){
        if (rec->table[i] != NULL){
            if( rec->table[i]->find_attr(rec->table[i], var_node->varchar_value) ){
                tableNumbersWithAttr++;
            }
                
        }
        else break;
    }
    if(tableNumbersWithAttr > 1){
        printf("\nError! attrname: %s is not in only one table\n\n", var_node->varchar_value);
        return true;
    }
    else if(tableNumbersWithAttr < 1){
        printf("\nError! nattrname: %s doesn't in the tables.\n\n", var_node->varchar_value);
        return true;
    }
    else {
        return false;
    }
}
