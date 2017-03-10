
#ifndef __NODE_H__
#define __NODE_H__

#define MAX_ATTR_NUM 10

typedef enum {
    DATA_TYPE_INT,
    DATA_TYPE_VARCHAR
}data_type_e;

typedef enum {
    CMD_TYPE_CREATE_TABLE

}cmd_type_e;

typedef struct __ATTR_NODE_HEADER_S__ {
    data_type_e  data_type;
    char *name;
    struct __ATTR_NODE_HEADER_S__ *head;
    struct __ATTR_NODE_HEADER_S__ *tail;
    struct __ATTR_NODE_HEADER_S__ *next;
}attr_node_header_t;

typedef struct {
    attr_node_header_t *header;
    int int_num;
    char *varchar_str;
} attr_node_t;

typedef struct {
    char *table_name;
    unsigned int attr_num;
    attr_node_t *attr[MAX_ATTR_NUM]; 
} create_table_node_t;

typedef struct {
    cmd_type_e type;
    void *cmd_info;
} cmd_req;

attr_node_header_t *sql_create_attr(char *name, int data_type);
attr_node_header_t *sql_attr_collect(attr_node_header_t *list, attr_node_header_t *node);
void sql_attr_head_set(attr_node_header_t *head_node);
void sql_recursive_printf_node(attr_node_header_t *list);
#endif
