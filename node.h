
#ifndef __NODE_H__
#define __NODE_H__
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "dbwriter.h"
#include "page.h"
#include "bplus.h"
#include "index.h"
//0508
#define MAX_ATTR_NUM 20
#define MAX_VARCHAR_LEN 9999
#define MAX_TUPLE_ATTR_HASH_SIZE 32
#define MAX_TABLE_ENTRY 128
#define CALLOC_MEM(type, n) (type *)calloc((n),sizeof(type))
#define CALLOC_CHK(node) assert(node && "out of heap\n")            

typedef struct __VAR_S__ var_node_t;
typedef struct __ATTR_NODE_HEADER_S__ attr_node_header_t;
typedef struct __ATTR_NODE_S__ attr_node_t;
typedef struct __COL_LIST_NODE_S__ col_node_t;
typedef struct __TABLE_NODE__ table_node_t;
typedef struct stmt_node_s stmt_node_t;
typedef enum {
    DATA_TYPE_NAME = 0,
    DATA_TYPE_INT = 50000,
    DATA_TYPE_PREFIX = 70000,
    DATA_TYPE_PREFIX_STAR = 90000,
    DATA_TYPE_VARCHAR = 130000,
    DATA_TYPE_UNDEFINE = 99999,
    
} data_type_e;

typedef enum {
    COL_ATTR_PRIKEY = 0,
    COL_ATTR_VALID = 1,
    COL_ATTR_INVALID =10
} col_attr_e;


typedef enum {
    STMT_TYPE_CREATE_TABLE,
    STMT_TYPE_INSERT_TUPLE,
    STMT_TYPE_SELECT_TUPLE,
    STMT_TYPE_CREATE_INDEX,
    STMT_TYPE_SHOW_LOG,
    STMT_TYPE_IMPORT_FILE,
    STMT_TYPE_TEST_SEL
}stmt_type_e;

typedef enum {
    EXPR_TYPE_BASIC_VAR,
    EXPR_TYPE_COMPARISON,
    EXPR_TYPE_AGGREGATION,
    EXPR_TYPE_LOGIC
} expr_type_e;

typedef enum {
    CREATE_DEF_TYPE_ATTR,
    CREATE_DEF_TYPE_PK_COL_LIST
} cret_def_e;

struct __ATTR_NODE_HEADER_S__ {
    data_type_e  data_type;
    int varchar_len;
    uint16_t col_attr;
    char *name;

    bool (*is_type_match)(attr_node_header_t *self, data_type_e type);
    bool (*is_data_valid)(attr_node_header_t *self, var_node_t *var_node);
    struct __ATTR_NODE_HEADER_S__ *head;
    struct __ATTR_NODE_HEADER_S__ *tail;
    struct __ATTR_NODE_HEADER_S__ *next;
};


typedef struct {

    union {
        char *varchar_value;
        int int_value;
    };
    int var_len;
} attr_node_value_t;

struct __ATTR_NODE_S__{
    attr_node_header_t *header;
    attr_node_value_t *value;
    void (*add_hdr)(attr_node_t *self, attr_node_header_t *hdr);
    bool (*set_value)(attr_node_t *self, var_node_t *vals_info);
    struct __ATTR_NODE_S__ *prev;
    struct __ATTR_NODE_S__ *next;
};

typedef struct __TUPLE_NODE_S__ tuple_t;
        
struct __TUPLE_NODE_S__{
    attr_node_t *attr[MAX_TUPLE_ATTR_HASH_SIZE];
    uint16_t pageId;
    uint16_t offset;
    void (*add_attr_vals)(tuple_t *self, attr_node_t *attrVal);
    attr_node_t *(*find_attr_vals)(tuple_t *self, char *name);
    struct __TUPLE_NODE_S__ *next;
    struct __TUPLE_NODE_S__ *prev;
};

typedef struct {
    bp_db_t tree;
    char *name;
} bptree_t;
struct __TABLE_NODE__ { 
    BP_WRITER_PRIVATE
    unsigned int attr_num;
    unsigned int pkey_num;
    unsigned int tuple_num;
    char *name;
    attr_node_header_t *attr[MAX_ATTR_NUM]; 
    attr_node_header_t *pkey_attr_head;
    attr_node_header_t *pkey_attr_tail;
    int16_t curr_page;
    db_page_t pageTable[MAX_PAGE_NUM_IN_TABLE];
    bptree_t btree[4];
    uint8_t btree_num;
    bool (*set_attr)(table_node_t *self, attr_node_header_t *attr_node_hdr);
    attr_node_header_t *(*find_attr)(table_node_t *self, char *attrName);
    bool (*chk_col_list)(table_node_t *self, col_node_t *col_list);
    void (*add_prikey_attr)(table_node_t *self, attr_node_header_t *pkey_attr);
    bool (*chk_duplc)(table_node_t *self, tuple_t *tuple);
    void (*add_tuple)(table_node_t *self, tuple_t *tuple);
    tuple_t *tuple_list_head;
    tuple_t *tuple_list_tail;
    struct __TABLE_NODE__ *next;
};

struct stmt_node_s{
    stmt_type_e type;
    void *stmt_info;
    void (*stmt_save)(stmt_node_t *self, stmt_type_e type, void *info);

};


struct __COL_LIST_NODE_S__{
    char *name;
    struct __COL_LIST_NODE_S__ *head;
    struct __COL_LIST_NODE_S__ *tail;
    struct __COL_LIST_NODE_S__ *next;
};

struct __VAR_S__{
    data_type_e type;
    int int_value;
    char *varchar_value;
    int varchar_len;
    char *prefix_value;
    int prefix_len;
    struct __VAR_S__ *next;
};//variable node



typedef struct __EXPR_NODE_S__{
    expr_type_e type;
    void *expr_info;
    struct __EXPR_NODE_S__ *next;
} expr_node_t;

typedef struct __INSERT_VALS_NODE_S__{
    var_node_t *info;   
    struct __INSERT_VALS_NODE_S__ *head;    
    struct __INSERT_VALS_NODE_S__ *tail;    
    struct __INSERT_VALS_NODE_S__ *next;    
} insert_vals_node_t;

typedef struct {
    char *table_name;
    col_node_t *col_list;
    insert_vals_node_t *insr_vals_list;
}insert_stmt_t;

typedef struct {
    char *table_name;
    attr_node_header_t *attr_list;
}cret_tbl_stmt_t;

typedef struct {
    cret_def_e type;
    void *cret_def_info;
}cret_def_node_t;

typedef enum {
    CMP_TYPE_GREATER = 2,
    CMP_TYPE_LESS = 1,
    CMP_TYPE_EQUAL = 4,
    CMP_TYPE_NOTEQUAL = 3
}cmp_type_e;//0401

typedef struct __COMPARISON_S__{
    cmp_type_e type;
    var_node_t *left;
    var_node_t *right;
} comparison_node_t;//0401

typedef enum {
    LGC_TYPE_AND,
    LGC_TYPE_OR,
     LGC_TYPE_INVALID
}lgc_type_e;//0401

typedef struct __LOGIC_S__{
    lgc_type_e type;
    expr_node_t *left;
    expr_node_t *right;
} logic_node_t;//0401//0405//

typedef enum {
    AGGR_TYPE_COUNT = 1,
    AGGR_TYPE_SUM =2
}aggregation_type_e;//0409

typedef struct __AGGREGATION_S__{
    aggregation_type_e type;
    bool is_star;
    var_node_t *attr_info;
} aggregation_node_t;//0409


typedef struct __SELECT_COL_LIST_NODE_S__{
    char *alias_name;
    void *col_info;
    bool is_star;
    bool is_prefix_dot_star;
    bool is_aggregation;
    struct __SELECT_COL_LIST_NODE_S__ *head;
    struct __SELECT_COL_LIST_NODE_S__ *tail;
    struct __SELECT_COL_LIST_NODE_S__ *next;
}select_col_node_t;//0401


typedef struct __SELECT_TABLE_LIST_NODE_S__{
    char *alias_name;
    var_node_t *table_info;
    struct __SELECT_TABLE_LIST_NODE_S__ *head;
    struct __SELECT_TABLE_LIST_NODE_S__ *tail;
    struct __SELECT_TABLE_LIST_NODE_S__ *next;
}select_table_node_t;//0401

typedef struct __SELECT_OPT_LIST_NODE_S__{
    /* Use for COUNT and SUM */
}select_opt_node_t;//0404

typedef struct {
    select_col_node_t* select_col_list;
    select_table_node_t* select_table_list; 
    expr_node_t* select_qualifier;
}select_stmt_t;//0404


#define MAX_SELECT_JOIN_TABLE 2

typedef enum {
    ERR_TYPE_DATA_TYPE_NOT_MATCH,
    ERR_TYPE_ATTR_NOT_EXIST
} err_msg_e;

typedef struct __MAP_TABLE_NAME__ {
    char *alias;
    char *tableName;
    struct __MAP_TABLE_NAME__ *next;
} map_table_name_t;

typedef struct __TUPLE_CONN__ tuple_cnn_t;
struct __TUPLE_CONN__{
    table_node_t *table;
    tuple_t *tuple;
    int nextQualNum;
    struct __TUPLE_CONN__ *nextRel;
    struct __TUPLE_CONN__ *prevRel;
    struct __TUPLE_CONN__ *siblHead;
    struct __TUPLE_CONN__ *siblTail;
    struct __TUPLE_CONN__ *siblNext;
    struct __TUPLE_CONN__ *siblPrev;
    struct __TUPLE_CONN__ *next;
};
typedef struct __CMP_EVAL_S__ {
    lgc_type_e type;
    comparison_node_t *cmp;
    int cmpL_tblIdx;
    int cmpR_tblIdx;
    struct __CMP_EVAL_S__ *next;
} cmp_eval_t; //comparison evaluation 

typedef struct {
    
    cmp_eval_t *head;
    cmp_eval_t *tail;
} cmp_eval_rec_t;


typedef struct __SEL_TARGET_ATTR__ sel_attr_t;
typedef struct __SELECT_RECORD__ {
    table_node_t *table[MAX_SELECT_JOIN_TABLE];
    cmp_eval_rec_t cmpForTbl[MAX_SELECT_JOIN_TABLE];
    cmp_eval_t  *cmpJoin;
    sel_attr_t  *attrList;
    tuple_cnn_t  *current;
    tuple_cnn_t  *currTail;
    tuple_cnn_t  *head;
    tuple_cnn_t  *tail;
    bool isNoWhere;
    int tableNum;
    int tableRec;
    sel_attr_t* attr_list;
    map_table_name_t *mapTbl;
    int tupleNum;
    FILE *log;
    lgc_type_e lgcOp;
    err_msg_e errMsg;
} sel_rec_t;

struct __SEL_TARGET_ATTR__{
     char *output_Name; /// Use for output. ex: "COUNT(*)" or "Student.ID" or "s.ID"......
     char *table_Name; // which table is the attr in.
     char *attr_Name;
     bool isPrintAll;// for * case

     aggregation_type_e isAggregation;
     struct __SEL_TARGET_ATTR__ *next;
} ;//0410



#define ATTR_PRIKEY (1<<COL_ATTR_PRIKEY)
attr_node_header_t *sql_create_attr(char *name, int data_type, uint16_t col_attr);
attr_node_header_t *sql_attr_collect(attr_node_header_t *list, attr_node_header_t *node);
attr_node_header_t *sql_attr_head_set(attr_node_header_t *head_node);
void sql_recursive_printf_node(attr_node_header_t *list);
table_node_t *sql_create_table(char *table_name, attr_node_header_t *attr_list);
void sql_handle_table (table_node_t *table);
void sql_printf_attr(attr_node_header_t *node);
col_node_t *sql_col_list_node_create(char *name, col_node_t *list, bool is_head);
void sql_print_col_node(col_node_t *list);
stmt_node_t *sql_insert_stmt_create(char *table_name, col_node_t *col_name_list, insert_vals_node_t *insr_vals_list);
void sql_stmt_handle(stmt_node_t *stmt);
bool sql_insert_stmt_handle(insert_stmt_t *insr_stmt);
insert_vals_node_t *sql_insert_vals_node_create(expr_node_t *expr_node, insert_vals_node_t *list, bool is_head);
expr_node_t *sql_expr_basic_data_node_create(data_type_e type, int int_val, char *varchar_val, char *prefix_val);
void sql_output_insert_result_to_file(insert_stmt_t *stmt);
attr_node_header_t *sql_cret_def_handle(attr_node_header_t *list, cret_def_node_t *cret_def_node);
attr_node_t *sql_attr_node_create_and_init(attr_node_header_t *hdr);
attr_node_header_t *sql_attr_header_node_create_and_init(char *name);
void sql_cret_tbl_page_init(table_node_t *tbl, uint16_t pageId);

cret_def_node_t *sql_cret_def_pk_def_node_create(col_node_t *col_node);
cret_def_node_t * sql_cret_def_attr_declar_node_create(char *name, int data_type, uint16_t col_attr);
void sql_free_attr_header_list(attr_node_header_t *attr_node);
stmt_node_t *sql_show_table_content(char *name);
stmt_node_t *sql_show_all_table(void);
select_col_node_t *sql_select_col_node_create(expr_node_t *expr_node, char *alias_name, bool is_prefix_dot_star);//0401
select_col_node_t *sql_select_col_list_create(select_col_node_t *col_node, select_col_node_t *list, bool is_head, bool is_star);//0401
select_table_node_t *sql_select_table_node_create(char *table_name, char *prefix, char *alias_name);//0401
select_table_node_t *sql_select_table_list_create(select_table_node_t *talbe_node, select_table_node_t *list, bool is_head);//0401
expr_node_t *sql_expr_comparison_node_create(cmp_type_e cmp_type, expr_node_t *left, expr_node_t *right);//0401
expr_node_t* sql_expr_logic_node_create(lgc_type_e lgc_type, expr_node_t* left, expr_node_t* right);//0401

stmt_node_t *sql_select_stmt_create(stmt_type_e stmt_type, select_col_node_t* select_col_list, select_table_node_t* select_table_list, expr_node_t* select_qualifier);//0404
bool sql_select_stmt_handle(select_stmt_t *select_stmt);

stmt_node_t *sql_cret_table_stmt_create(char *table_name, attr_node_header_t *attr_list);
stmt_node_t *sql_import_file(char *name, char *lastName);

expr_node_t *sql_expr_aggregation_node_create(aggregation_type_e type, bool is_star, expr_node_t *expr_node);

void sql_init(void);
stmt_node_t *sql_stmt_act_init(void);

/**** TEST FUNC ***/

stmt_node_t *sql_sel_stmt_hdl(select_stmt_t *selStmt);
select_stmt_t *sql_test_select(void);

/******/
//0409

/******/
//0410 errchk
bool sql_select_errchk(sel_rec_t *rec, select_stmt_t *selStmt);
bool sql_select_tablename_errchk(sel_rec_t *rec, select_table_node_t *table_list);
bool sql_select_attrname_errchk(sel_rec_t *rec, select_col_node_t *attr_chk);

bool sql_select_qulifier_errchk(sel_rec_t *rec, expr_node_t* select_qualifier);
bool sql_select_cmp_errchk(sel_rec_t *rec, expr_node_t* expr_node);

bool sql_select_var_node_errchk(sel_rec_t *rec, var_node_t *var_node);
bool sql_select_data_type_prefix_errchk(sel_rec_t *rec, var_node_t *var_node);
bool sql_select_data_type_name_errchk(sel_rec_t *rec, var_node_t *var_node);// datatype check
bool sql_select_data_type_prefix_star_errchk(sel_rec_t *rec, var_node_t *var_node);
//0410 errchk
#endif
