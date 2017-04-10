#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "node.h"

#define MAX_TABLE_ENTRY 128
#define MAX_STMT_NUM_SUPPORT 20
#define MAX_IMPORT_FILE_NAME_LENGTH 100
#define CALLOC_MEM(type, n) (type *)calloc((n),sizeof(type))
#define CALLOC_CHK(node) assert(node && "out of heap\n")            

typedef void (*stmt_dstry_func)(stmt_node_t*);
static table_node_t *table_list[MAX_TABLE_ENTRY] = { NULL };
stmt_dstry_func *stmt_dstry;
bool sql_is_dup_tuple_chk(table_node_t *self, tuple_t *new_tuple);
static tuple_t *sql_tuple_create_and_init(void);
bool sql_insr_check_col_list_valid(table_node_t *self, col_node_t *colNodeList);

attr_node_header_t *sql_insr_find_attr_in_table(table_node_t *tbl, char *attrName);


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
            printf("error: unknown data type\n");
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
    tuple->next = self->tuple_list_head;
    self->tuple_list_head = tuple;
    self->tuple_num ++;
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
// true: means duplicated tuple was created before
// we should free all the mem created for new insertion 
// free
bool sql_is_dup_tuple_chk(table_node_t *table, tuple_t *new_tuple)
{
    tuple_t *tuple_in_tbl = table->tuple_list_head;
    while (tuple_in_tbl) {
        if (sql_compare_prikey_with_pkname(new_tuple, tuple_in_tbl, table->pkey_attr_head))
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
    tuple->add_attr_vals = sql_tuple_attr_insert;
    tuple->find_attr_vals = sql_find_attr_in_tuple;
    return tuple;
}

bool sql_insr_stmt_tuple_create(table_node_t *tbl, col_node_t *col_list, insert_vals_node_t *vals_list)
{
    attr_node_t *attrNdHead = NULL;
    bool result = true;
    if (col_list)
        result = sql_insr_create_attr_node_with_self_dfn_order(tbl, col_list, vals_list, &attrNdHead);
    else
        result = sql_insr_create_attr_node_by_default(tbl, vals_list, &attrNdHead);
    
    if (result && attrNdHead) {
        tuple_t *tuple = sql_tuple_create_and_init();
        tuple->add_attr_vals(tuple, attrNdHead);
        if (!tbl->chk_duplc(tbl, tuple)) {
            tbl->add_tuple(tbl, tuple);
            return true;
        } else {
            printf("duplicated\n");
            // print out the error message
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
    return true;

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
    //sql_insert_stmt_free_mem(insr_stmt);
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
    attr_node_header_t *newNd = CALLOC_MEM(attr_node_header_t, 1);
    CALLOC_CHK(newNd);
    newNd->name = name;
    newNd->is_data_valid = sql_check_data_validation; 
    newNd->is_type_match = sql_check_data_type_match;
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
    switch (col_attr)
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
    /*
    if (name)
        col_node->name = strdup(name);
    col_node->next = NULL;
    if (is_head) {
        col_node->head = col_node;
        col_node->tail = col_node;
        return col_node;
    }
    else {
        col_node->head = NULL;
        col_node->tail = NULL;
        list->tail->next = col_node;
        list->tail = col_node;
        return list;
   }*/
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
        printf("table name: %s\n", table->name);
        int i = 0;
        for (i = 0; i < table->attr_num; i++) {
            printf("\t%s", table->attr[i]->name);
            if(table->attr[i]->col_attr&ATTR_PRIKEY)
                printf("(P)");
        }
        printf("\n");
        if (table->tuple_num) {
        tuple_nd = table->tuple_list_head;
            while (tuple_nd) {
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
                printf("\n");
            }
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

    if (table) {
    	sql_print_table(table);
        /*printf("table name: %s\n", table->name);
        int i = 0;
        for (i = 0; i < table->attr_num; i++) {
            printf("\t%s", table->attr[i]->name);
            if(table->attr[i]->col_attr&ATTR_PRIKEY)
                printf("(P)");
        }
        printf("\n");
        if (table->tuple_num) {
        tuple_nd = table->tuple_list_head;
            while (tuple_nd) {
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
                printf("\n");
            }
        }*/
    } else {
        printf("error: can not find the table:%s\n", name);
    }
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
//0401//0405//
select_col_node_t *sql_select_col_node_create(expr_node_t *expr_node, char *alias_name){
    //return a col_node to select_expr->select_expr_list->select_stmt
    select_col_node_t *select_col_node = CALLOC_MEM(select_col_node_t, 1);
    CALLOC_CHK(select_col_node);
    
    if(alias_name){
        select_col_node->alias_name = strdup(alias_name);
    }   
    else{
        select_col_node->alias_name = NULL;
    }//0409
    select_col_node->is_star = false;

    if (expr_node == NULL || (expr_node->type != EXPR_TYPE_BASIC_VAR && expr_node->type != EXPR_TYPE_AGGREGATION ) || expr_node->expr_info == NULL) {
        free(select_col_node);
        printf("\nexpr is wrong!!!--sql_select_col_node_create()\n");
        return NULL;
    }
    else {
        select_col_node->col_info = (var_node_t *)expr_node->expr_info;
        return select_col_node;
    }
}//0401//0405

select_col_node_t *sql_select_col_list_create(select_col_node_t *col_node, select_col_node_t *list, bool is_head, bool is_star){
    //return a head col_node to select_expr_list->select_stmt
    if(is_star){
        select_col_node_t *select_col_node = CALLOC_MEM(select_col_node_t, 1);
        CALLOC_CHK(select_col_node);
        select_col_node->is_star = true;
        return select_col_node;
    }
    
    if(col_node){
        if(is_head){
            col_node->head = col_node;
            col_node->tail = col_node;
            return col_node;
        }
        else{
            list->tail->next = col_node;
            list->tail = col_node;
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

    
    //Check whether it is prefix type or not.
    if (prefix) {
        var_node->type = DATA_TYPE_PREFIX;
        var_node->varchar_value = strdup(table_name);
        var_node->varchar_len = strlen(table_name)-2;
        var_node->prefix_value = strdup(prefix);
        var_node->prefix_len = strlen(prefix)-2;
        table_node->table_info = var_node;
        
    }
    else {
        var_node->type = DATA_TYPE_VARCHAR;
        var_node->varchar_value = strdup(table_name);
        var_node->varchar_len = strlen(table_name)-2;
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
    if (select_col_list ==NULL || select_col_list->col_info == NULL){
        printf("\nError: \"select_col_list\" error in sql_select_table_list_create().\n");
        return NULL;
    }
    if (select_table_list ==NULL || select_table_list->table_info == NULL){
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

bool sql_select_stmt_handle(select_stmt_t *select_stmt)
{
    /*Refered to sql_show_table_content() */
    
    /*Decode "From" instruction to get the table to use and construct an aliases-table.*/
    /*Decode "Where" instruction*/
    /*Decode "Select" instruction*/
        /*check whether it is aggregation function for every col_node. */
    return true;   
}//0401//0405





//sql_select_stmt_handle ->(å¯åè) sql_show_table_content
//sql_select_col_node_create -> easy
//sql_select_col_list_create -> sql_col_list_node_create
//sql_select_table_node_create -> easy
//sql_select_table_list_create -> sql_col_list_node_create
//sql_expr_comparison_node_create -> easy
//sql_expr_logic_node_create -> easy
//sql_select_stmt_create -> easy
//
//

char *sql_sel_find_tbl_name(sel_rec_t *rec, char *pfx)
{
    map_table_name_t *mapTbl = rec->mapTbl;
    while (mapTbl) {
        if (strcmp(mapTbl->tableName, pfx)== 0 || strcmp(mapTbl->alias, pfx) == 0)
            return mapTbl->tableName;
    }
    return NULL;
}

bool sql_sel_collect_table(sel_rec_t *rec, select_table_node_t *tableList)
{
    int i = 0;
    table_node_t *table = NULL;
    select_table_node_t *selTable = tableList;
    map_table_name_t *mapTbl;
    map_table_name_t **mapTblHd = &mapTbl;
    while (selTable) {
        table = sql_find_table(selTable->table_info->varchar_value);
        if (table) {
            *mapTblHd = CALLOC_MEM(map_table_name_t, 1);
            CALLOC_CHK(*mapTblHd);
            (*mapTblHd)->alias = tableList->alias_name;
            (*mapTblHd)->tableName = tableList->table_info->varchar_value;
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
        table_node_t *table[MAX_SELECT_JOIN_TABLE];
        int i = 0;
        int matchNum = 0;
        int matchIdx = -1;
        char *tableName = NULL;
        if (var->type == DATA_TYPE_PREFIX) {
            //tableName = sql_transl_alias(var->prefix_value);
            tableName = var->prefix_value;
        }   
        for (i = 0; i < MAX_SELECT_JOIN_TABLE; i++)
        {
            if (sql_insr_find_attr_in_table(rec->table[i], var->varchar_value)) {
                
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
        //rec->lgcOp = LGC_TYPE_INVALID;
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
    cmp_eval_t *cmpE = rec->cmpForTbl[idx].head;
    return cmpE;
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
                            printf("LGC_TYPE_OR\n");
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
                            printf("LGC_TYPE_AND\n");
                            
                            break;
                        case LGC_TYPE_OR:
                            result = (result || sql_sel_qualifier(rec, cmpEval->next, tuple));
                            printf("LGC_TYPE_OR\n");
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
    comparison_node_t *cmp = cmpEval->cmp;
    var_node_t *cmpL = cmp->left;
    var_node_t *cmpR = cmp->right;
    var_node_t *cmpThis  = NULL;
    tuple_t *tuplePrev = tplCnn->tuple;
    tuple_cnn_t * tplCnnThis = NULL;
    bool result = false;
    int idx = -1;
    attr_node_t *attrPrev= tuplePrev->find_attr_vals(tuplePrev, cmpL->varchar_value);
    if (!attrPrev) {
        attrPrev = tuplePrev->find_attr_vals(tuplePrev, cmpR->varchar_value);
        idx = cmpEval->cmpL_tblIdx;
        cmpThis = cmpL;
    } else {
        idx = cmpEval->cmpR_tblIdx;
        cmpThis = cmpR;
    }
    if (attrPrev) {
        cmp_eval_t *cmpEvalTbl = sql_get_cmp_from_table(rec, idx);
        result = (cmpEvalTbl == NULL);
        table_node_t *table = rec->table[idx];
        tuple_t *tuple = table->tuple_list_head;
        bool evalTwo = ((cmpEval!=NULL)&&(cmpEvalTbl!=NULL));
        attr_node_t *attrThis = NULL;
        int i;
        int qualTupleNum = 0;
        for (i = 0; i < table->tuple_num; i++) {
            attrThis = tuple->find_attr_vals(tuple, cmpThis->varchar_value);
            result = result || sql_sel_qualifier(rec, cmpEvalTbl, tuple);

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
    }
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
    tuple_t *tupleHead;
    tuple_t **p_tuple = &tupleHead; 
    for (i = 0; i < tplNum; i++) {
        *p_tuple = sql_tuple_create_and_init();
        p_tuple = &((*p_tuple)->next);
    }
    return tupleHead;
}

attr_node_header_t *sql_look_for_attrHead(sel_rec_t *rec, sel_attr_t *attr, int *idx)
{
    if (attr->tableName && attr->attrName) {
        int i;
        for (i = 0; i < rec->tableNum; i++) {
            if (strcasecmp(rec->table[i]->name, attr->tableName) == 0) {
                *idx = i;
                return rec->table[i]->find_attr(rec->table[i], attr->attrName);
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
void sql_transl_to_tbl(sel_rec_t *rec, table_node_t *tbl)
{
    sel_attr_t *sAttr = rec->attrList;
    int i = 0;
    tbl->name = strdup("tmp");
    attr_node_header_t *attrHdDst, *attrHdSrc;
    while (sAttr) {
        tuple_t *tupleAdd = tbl->tuple_list_head;
        attr_node_t *attrNd = NULL;
        tuple_t *tupleTgt = NULL;
        attr_node_value_t *attrVal = NULL;
        int tblIdx = -1;
        int repNum = 0;
        bool isRep = false;
        attrHdSrc = sql_look_for_attrHead(rec, sAttr, &tblIdx);
        attrHdDst = CALLOC_MEM(attr_node_header_t, 1);
        CALLOC_CHK(attrHdDst);
        sql_attr_node_header_cpy(attrHdDst, attrHdSrc);
        attrHdDst->name = strdup(sAttr->attrName);
        tbl->attr[i] = attrHdDst;
        tuple_cnn_t *tupleRec = rec->head;
        tuple_cnn_t *tupleDeep = rec->head;
        while (tupleDeep) {
            if (strcasecmp(tupleDeep->table->name, sAttr->tableName) == 0){
                break;
            }
            tupleDeep = tupleDeep->nextRel;
        }
        isRep = (tupleDeep->nextQualNum > 0);
        repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;// should be previos level node
        if (isRep) {
            tupleTgt = tupleDeep->tuple;   
            attrVal = (tupleTgt->find_attr_vals(tupleTgt, sAttr->attrName))->value;
        }
        while (tupleAdd) {
        
            if (repNum == 0) {
                tupleRec = tupleRec->next;
                tupleDeep = tupleRec;
                while (tupleDeep) {
                    if (strcasecmp(tupleDeep->table->name, sAttr->tableName) == 0){
                        break;
                    }
                    tupleDeep = tupleDeep->nextRel;
                }
                repNum = (tupleRec->nextQualNum > 0) ? tupleRec->nextQualNum : 1;
                if (isRep) {
                    tupleTgt = tupleDeep->tuple;   
                    attrVal = (tupleTgt->find_attr_vals(tupleTgt, sAttr->attrName))->value;
                }
            }
            if (!isRep) {
                tupleTgt = tupleDeep->tuple;
                attrVal = (tupleTgt->find_attr_vals(tupleTgt, sAttr->attrName))->value;
                tupleDeep = tupleDeep->siblNext;
            }
            attrNd = CALLOC_MEM(attr_node_t, 1);
            CALLOC_CHK(attrNd);
            attrNd->header = attrHdDst;
            attrNd->value = attrVal;
            tupleAdd->add_attr_vals(tupleAdd, attrNd);
            tupleAdd = tupleAdd->next;
            repNum--;
        }
        sAttr = sAttr->next;
        i++;
    }
    tbl->attr_num = i;
    tbl->tuple_num = rec->tupleNum;
}

sel_attr_t *sql_make_sel_attr_node(char *newName, char *tblName, char *attrName, bool isAll)
{
    sel_attr_t *sAttr = CALLOC_MEM(sel_attr_t, 1);
    CALLOC_CHK(sAttr);

    if (newName)
        sAttr->newName = strdup(newName);

    sAttr->tableName = strdup(tblName);
    sAttr->attrName = strdup(attrName);
    sAttr->isPrintAll = isAll;
    return sAttr;
}

void sql_sel_temp_select_list_collect(sel_rec_t *rec)
{ 
    char *selecTest[][3] = {
        {NULL, "Author", "name"},
        {NULL, "Book", "title"},
    };
    int num = sizeof(selecTest) / sizeof(selecTest[0]);
    int i;
    sel_attr_t *sAttr;
    sel_attr_t **p_sAttr = &sAttr;
    for (i = 0; i < num; i++) {
        *p_sAttr = sql_make_sel_attr_node(selecTest[i][0],
                                          selecTest[i][1],
                                          selecTest[i][2], false);
        p_sAttr = &((*p_sAttr)->next);
    }
    rec->attrList = sAttr;
}


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


/******/


stmt_node_t *sql_import_file(char *name)
{
    FILE *import;
    extern FILE *yyin;
    char fileName[MAX_IMPORT_FILE_NAME_LENGTH];
    if (strlen(name) < (MAX_IMPORT_FILE_NAME_LENGTH-4))
        strcpy(fileName, name);
    strcat(fileName,".sql");
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
void sql_init()
{
    /* stmt destroy function register*/
    stmt_dstry = CALLOC_MEM(stmt_dstry_func, 20);
    CALLOC_CHK(stmt_dstry);
    stmt_dstry[STMT_TYPE_CREATE_TABLE] = sql_cret_tbl_stmt_destroy;
    stmt_dstry[STMT_TYPE_INSERT_TUPLE] = sql_insr_tpl_stmt_destroy;

}


/**************TEST FUNCTION***************/

#define MAX_TARGET_NUM 1
#define MAX_TABLE_NUM 2

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
    //selStmt->select_qualifier = NULL;
    return selStmt;
}
