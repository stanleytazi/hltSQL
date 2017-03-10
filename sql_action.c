#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


void sql_handle_table (create_table_node_t *table) 
{
    int num  = 0;
    attr_node_header_t *node = NULL;
    printf("============\n");
    if (table) {
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
    while (node) {
        table->attr[attr_num] = (attr_node_t *) malloc(sizeof(attr_node_t));
        if ( !table->attr[attr_num])
            return NULL;
        table->attr[attr_num]->header = node;
        attr_num ++;
        node = node->next;
    }
    // TODO: check the num of attr
    table->attr_num = attr_num;
    return table;
}

attr_node_header_t  *sql_create_attr(char *name, int data_type)
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


