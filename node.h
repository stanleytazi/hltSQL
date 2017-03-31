
#ifndef __NODE_H__
#define __NODE_H__
#include <stdbool.h>

#define MAX_ATTR_NUM 20
#define MAX_VARCHAR_LEN 9999
#define MAX_TUPLE_ATTR_HASH_SIZE 32

typedef struct __VAR_S__ var_node_t;
typedef struct __ATTR_NODE_HEADER_S__ attr_node_header_t;
typedef struct __ATTR_NODE_S__ attr_node_t;
typedef struct __COL_LIST_NODE_S__ col_node_t;
typedef enum {
    DATA_TYPE_NAME = 0,
    DATA_TYPE_INT = 50000,
    DATA_TYPE_VARCHAR = 130000,
    DATA_TYPE_UNDEFINE = 99999
} data_type_e;

typedef enum {
    COL_ATTR_PRIKEY = 0,
    COL_ATTR_VALID = 1,
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

struct __ATTR_NODE_HEADER_S__ {
    data_type_e  data_type;
    char *name;
    int varchar_len;
    uint16_t col_attr;

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
    void (*add_attr_vals)(tuple_t *self, attr_node_t *attrVal);
    attr_node_t *(*find_attr_vals)(tuple_t *self, char *name);
    struct __TUPLE_NODE_S__ *next;
    struct __TUPLE_NODE_S__ *prev;
};

typedef struct __TABLE_NODE__ table_node_t;
struct __TABLE_NODE__ {
    char *name;
    unsigned int attr_num;
    attr_node_header_t *attr[MAX_ATTR_NUM]; 
    unsigned int pkey_num;
    attr_node_header_t *pkey_attr_head;
    attr_node_header_t *pkey_attr_tail;
    unsigned int tuple_num;

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

typedef struct {
    stmt_type_e type;
    void *stmt_info;
    void (*stmt_save)(void *self, stmt_type_e type, void *info);

} stmt_node_t;


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
expr_node_t *sql_expr_basic_data_node_create(data_type_e type, int int_val, char *varchar_val);
void sql_output_insert_result_to_file(insert_stmt_t *stmt);
attr_node_header_t *sql_cret_def_handle(attr_node_header_t *list, cret_def_node_t *cret_def_node);

cret_def_node_t *sql_cret_def_pk_def_node_create(col_node_t *col_node);
cret_def_node_t * sql_cret_def_attr_declar_node_create(char *name, int data_type, uint16_t col_attr);
void sql_free_attr_header_list(attr_node_header_t *attr_node);
stmt_node_t *sql_show_table_content(char *name);
stmt_node_t *sql_show_all_table(void);
stmt_node_t *sql_cret_table_stmt_create(char *table_name, attr_node_header_t *attr_list);
void sql_init(void);
#endif
