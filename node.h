
#ifndef __NODE_H__
#define __NODE_H__
#include <stdbool.h>

#define MAX_ATTR_NUM 10
#define MAX_VARCHAR_LEN 9999
#define MAX_TUPLE_ATTR_HASH_SIZE 32
typedef enum {
    DATA_TYPE_INT = 50000,
    DATA_TYPE_VARCHAR = 130000
} data_type_e;

typedef enum {
    COL_ATTR_PRIKEY,
    COL_ATTR_VALID,
    COL_ATTR_INVALID =10
} col_attr_e;


typedef enum {
    STMT_TYPE_CREATE_TABLE,
    STMT_TYPE_INSERT_TUPLE,
    STMT_TYPE_SHOW_LOG
}stmt_type_e;

typedef enum {
    EXPR_TYPE_BASIC_VAR

} expr_type_e;

typedef enum {
    CREATE_DEF_TYPE_ATTR,
    CREATE_DEF_TYPE_PK_COL_LIST
} cret_def_e;

typedef struct __ATTR_NODE_HEADER_S__ {
    data_type_e  data_type;
    char *name;
    int varchar_len;
    bool is_PRIKEY;
    struct __ATTR_NODE_HEADER_S__ *head;
    struct __ATTR_NODE_HEADER_S__ *tail;
    struct __ATTR_NODE_HEADER_S__ *next;
}attr_node_header_t;


typedef struct {

    union {
        char *varchar_value;
        int int_value;
    };
    int var_len;
} attr_node_value_t;

typedef struct __ATTR_NODE_S__{
    attr_node_header_t *header;
    attr_node_value_t *value;
    struct __ATTR_NODE_S__ *prev;
    struct __ATTR_NODE_S__ *next;
} attr_node_t;


typedef struct __TUPLE_NODE_S__{
    attr_node_t *attr[MAX_TUPLE_ATTR_HASH_SIZE];
    struct __TUPLE_NODE_S__ *next;
    struct __TUPLE_NODE_S__ *prev;
} tuple_t;

typedef struct __CREATE_TABLE_NODE__{
    char *table_name;
    unsigned int attr_num;
    attr_node_t *attr[MAX_ATTR_NUM]; 
    unsigned int prim_key_num;
    attr_node_t *prim_key_attr;
    unsigned int tupleNum;
    tuple_t *tuple_list_head;
    tuple_t *tuple_list_tail;
    struct __CREATE_TABLE_NODE__ *next;
} create_table_node_t;

typedef struct {
    stmt_type_e type;
    void *stmt_info;
    void (*stmt_save)(void *self, stmt_type_e type, void *info);

} stmt_node_t;


typedef struct __COL_LIST_NODE_S__{
    char *name;
    struct __COL_LIST_NODE_S__ *head;
    struct __COL_LIST_NODE_S__ *tail;
    struct __COL_LIST_NODE_S__ *next;
}col_node_t;

typedef struct __VAR_S__{
    data_type_e type;
    int int_value;
    char *varchar_value;
    int varchar_len;
    struct __VAR_S__ *next;
} var_node_t;//variable node



typedef struct __EXPR_NODE_S__{
    expr_type_e type;
    void *expr_info;
    struct __EXPR_NODE_S__ *next;
} expr_node_t;

typedef struct __INSERT_VALS_NODE_S__{
    var_node_t *var_info;   
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
    cret_def_e type;
    void *cret_def_info;
}cret_def_node_t;


attr_node_header_t *sql_create_attr(char *name, int data_type, col_attr_e col_attr);
attr_node_header_t *sql_attr_collect(attr_node_header_t *list, attr_node_header_t *node);
attr_node_header_t *sql_attr_head_set(attr_node_header_t *head_node);
void sql_recursive_printf_node(attr_node_header_t *list);
create_table_node_t *sql_create_table(char *table_name, attr_node_header_t *attr_list);
void sql_handle_table (create_table_node_t *table);
void sql_printf_attr(attr_node_header_t *node);
col_node_t *sql_col_list_node_create(char *name, col_node_t *list, bool is_head);
void sql_print_col_node(col_node_t *list);
stmt_node_t *sql_insert_stmt_create(stmt_type_e stmt_type, char *table_name, col_node_t *col_name_list, insert_vals_node_t *insr_vals_list);
void sql_stmt_handle(stmt_node_t *stmt);
bool sql_insert_stmt_handle(insert_stmt_t *insr_stmt);
insert_vals_node_t *sql_insert_vals_node_create(expr_node_t *expr_node, insert_vals_node_t *list, bool is_head);
expr_node_t *sql_expr_basic_data_node_create(data_type_e type, int int_val, char *varchar_val);
void sql_output_insert_result_to_file(insert_stmt_t *stmt);
attr_node_header_t *sql_cret_def_handle(attr_node_header_t *list, cret_def_node_t *cret_def_node);

cret_def_node_t *sql_cret_def_pk_def_node_create(col_node_t *col_node);
cret_def_node_t * sql_cret_def_attr_declar_node_create(char *name, int data_type, col_attr_e col_attr);
void sql_free_attr_header_list(attr_node_header_t *attr_node);
stmt_node_t *sql_show_table_content(char *name);
#endif
