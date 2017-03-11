#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

#define MAX_TABLE_ENTRY 128
static create_table_node_t *table_list[MAX_TABLE_ENTRY] = { NULL };


unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str) {
            hash = hash * seed + (*str++);
        }

    return (hash & 0x7FFFFFFF);
}

void sql_handle_table (create_table_node_t *table) 
{
    int num  = 0;
    attr_node_header_t *node = NULL;
    printf("============\n");
    if (table) {
        int bucket_idx = BKDRHash(table->table_name) % MAX_TABLE_ENTRY;
        create_table_node_t **tmp = &table_list[bucket_idx];
        while (*tmp) {
            tmp = &((*tmp)->next);
        }
        *tmp = table;
        printf("bucket idx = %d\n", bucket_idx);
        printf("table name : %s\n", table->table_name);
        printf("\t\tattr number : %d\n", table->attr_num);
        while (num < table->attr_num) {
            node = table->attr[num]->header;
            printf("attr name=%s, dataType=%d, varLen=%d\n", node->name, node->data_type, node->varchar_len);
            num++;
        }
    }
    printf("============\n");
}
stmt_node_t *sql_create_stmt(stmt_type_e stmt_type, void *parsed_stmt)
{
    return NULL;
}

static void sql_stmt_save(stmt_node_t *self, stmt_type_e type, void *info)
{
    self->type = type;
    self->cmd_info = info;
}

stmt_node_t *sql_stmt_act_init()
{
    stmt_node_t *stmt_node = (stmt_node_t *) malloc(sizeof(stmt_node_t));
    stmt_node->stmt_save = sql_stmt_save;
    
    return stmt_node;
}

create_table_node_t *sql_find_table(char *table_name)
{
    if (table_name) {
        int bucket_idx = BKDRHash(table_name) % MAX_TABLE_ENTRY;
        create_table_node_t *table = table_list[bucket_idx];
        while (table) {
            if (strcasecmp(table_name, table->table_name) == 0) {
                break;
            }
            table = table->next;
        }
        return table;
    }
    return NULL;
}

stmt_node_t *sql_create_insert_stmt(stmt_type_e stmt_type, char *table_name, col_node_t *col_name_list, insert_vals_node_t *insr_vals_list)
{
    // find the table
    // check if primary key exist
    // check if NOT-NULL attr is NULL
    // check if data type match
return NULL;
}

char *sql_create_attr_varchar(int len)                   
{                                                        
    if (len <= 0)
        printf("the length varchar should be larger than zero\n");
    char *varchar_attr = (char *) malloc(sizeof(char)*len);
    return varchar_attr;                                 
}

create_table_node_t *sql_create_table(char *table_name, attr_node_header_t *attr_list) 
{
    int attr_num = 0;
    attr_node_t **prim_key_tail;
    attr_node_header_t *node = attr_list;
    create_table_node_t *table = (create_table_node_t *) malloc(sizeof(create_table_node_t));  
    if (!table) {
        printf("fail to allocate space for table creation\n");
        return NULL;
    }
    
    table->table_name = strdup(table_name);
    if (!table->table_name) {
        return NULL;
    }
    table->prim_key_num = 0;
    table->prim_key_attr = NULL;
    table->tuple_list = NULL;
    prim_key_tail = &(table->prim_key_attr);
    while (node) {
        table->attr[attr_num] = (attr_node_t *) malloc(sizeof(attr_node_t));
        if ( !table->attr[attr_num])
            return NULL;
        table->attr[attr_num]->header = node;
        if (node->is_PRIKEY) {
            table->prim_key_num ++;
            *prim_key_tail = table->attr[attr_num];
            prim_key_tail = &(table->attr[attr_num]->next);
        }
        attr_num ++;
        node = node->next;
    }
    // TODO: check the num of attr
    table->attr_num = attr_num;
    return table;
}

attr_node_header_t  *sql_create_attr(char *name, int data_type, col_attr_e col_attr)
{
    attr_node_header_t *new_node = (attr_node_header_t*)malloc(sizeof(attr_node_header_t));
    if (name)
        new_node->name = strdup(name);
    if (data_type > DATA_TYPE_VARCHAR 
        && data_type <= (DATA_TYPE_VARCHAR + MAX_VARCHAR_LEN)) {
        new_node->varchar_len = data_type - DATA_TYPE_VARCHAR;
        new_node->data_type = DATA_TYPE_VARCHAR;
    }
    else if (data_type == DATA_TYPE_INT) {
        new_node->data_type = DATA_TYPE_INT;
    }
    
    switch (col_attr)
    {
        case COL_ATTR_PRIKEY:
            new_node->is_PRIKEY = true;
            break;
        case COL_ATTR_VALID:
            new_node->is_PRIKEY = false;
            break;
        case COL_ATTR_INVALID:
        default:
            printf("invalid column attr.\n");
            break;
    }
    new_node->next = NULL;
    new_node->head = NULL;
    new_node->tail = NULL;
    printf("create attr name:%s, data type%d\n", new_node->name, new_node->data_type);
    return new_node;
}

void sql_attr_head_set(attr_node_header_t *head_node)
{
    if (head_node) {
        head_node->head = head_node;
        head_node->tail = head_node;
    }   
}
attr_node_header_t *sql_attr_collect(attr_node_header_t *list, attr_node_header_t *node)
{
    if (list->tail && node) {
        list->tail->next = node;
        list->tail = node;
    }
    return list;
}

void sql_printf_attr(attr_node_header_t *node)
{
    if (node) {
        printf("name=%s, dataType=%d\n", node->name, node->data_type);
    }
}

void sql_recursive_printf_node(attr_node_header_t *list)
{
    while (list) {
        printf("node name = %s\n", list->name);
        list = list->next;
    }
}


col_node_t *sql_col_list_node_create(char *name, col_node_t *list, bool is_head)
{
    col_node_t *col_node = (col_node_t *) malloc(sizeof(col_node_t));
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
    }
}

insert_vals_node_t *sql_insert_vals_node_create(expr_node_t *expr_node, insert_vals_node_t *list, bool is_head)
{
    insert_vals_node_t *insr_node = (insert_vals_node_t *) malloc(sizeof(insert_vals_node_t));
    if (expr_node && expr_node->type == EXPR_TYPE_BASIC_VAR && expr_node->expr_info)
        insr_node->var_info = (var_node_t *)(expr_node->expr_info);
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


expr_node_t *sql_expr_basic_data_node_create(data_type_e type, int int_val, char *varchar_val)
{
    var_node_t *data = (var_node_t *) malloc(sizeof(var_node_t));
    if (data)
        return NULL;
    switch(type) 
    {
        case DATA_TYPE_INT:
            data->int_value = int_val;
            break;
        case DATA_TYPE_VARCHAR:
            data->varchar_value = strdup(varchar_val);
            data->var_len = strlen(varchar_val);
            break;
        default:
            break;
    }
    data->type =  type;
    
    expr_node_t *expr_node = (expr_node_t *) malloc(sizeof(expr_node_t));  
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


