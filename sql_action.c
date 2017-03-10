#include <stdio.h>
#include <stdlib.h>
#include "node.h"
int sql_create_table(char *table_name) 
{
    return 0;   
   //{ emit("CREATE %d %d %d %s", $2, $4, $7, $5); free($5); }
}

attr_node_header_t  *sql_create_attr(char *name, int data_type)
{
    attr_node_header_t *new_node = (attr_node_header_t*)malloc(sizeof(attr_node_header_t));
    if (name)
        new_node->name = strdup(name);
    new_node->data_type = data_type;
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
