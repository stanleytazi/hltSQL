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
    self->stmt_info = info;
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

bool sql_check_prikey_exist(create_table_node_t *table, col_node_t *col_node)
{   unsigned int pkey_num = table->prim_key_num;
    attr_node_t *prikey = table->prim_key_attr;
    col_node_t *col = col_node; 
    char *attr_name;
    while (prikey) {
        attr_name = prikey->header->name;
        while (col) {
            if (strcasecmp(attr_name, col->name) == 0) {
                pkey_num--; 
                break;
            }
            col = col->next;
        }
        prikey = prikey->next;
    }
    return (pkey_num == 0);
}

bool sql_data_info_valid_chk(create_table_node_t *table, col_node_t *col_node, insert_vals_node_t *vals_node)
{
    // remember free col_node & var_node
    bool rtn = true;
    tuple_t *tuple_nd = NULL;
    attr_node_t *attr_nd = NULL;
    attr_node_t *attr_nd_prev = NULL;
    attr_node_t *attr_head = NULL;
    col_node_t *col = col_node;
    insert_vals_node_t *vals_nd = vals_node;
    int i = 0;
    if (col) {
        while (col) {
        for (i = 0; (i < table->attr_num) && rtn; i++) {
            if (strcasecmp(table->attr[i]->header->name, col->name) == 0) {
                var_node_t *var =  vals_nd->var_info;
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
                            if (var->varchar_len <= attr_nd->header->varchar_len) {
                                attr_nd->value->varchar_value = strdup(var->varchar_value);
                                attr_nd->value->var_len = var->varchar_len;
                            } else {
                                rtn = false;
                                printf("error: varchar len is too long\n");
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
                    } else {
                        if (attr_nd->value)
                            free(attr_nd->value);
                        free(attr_nd);
                        attr_nd = NULL;
                    }
                    break;
                    /*
                    attr_nd->head = (attr_node_header_t *) malloc(sizeof(attr_node_header_t));
                    if (!attr_nd->head) {
                        printf("no heap meme\n");
                        return NULL;
                    }
                    attr->head->data_type = var->type;
                    attr->head->name = strdup(col->name);
                    */
                }
                else {
                    printf("data type does not match\n");
                    rtn = false;
                }
            }
        }
        if (!attr_nd) {
            printf("col name: %s does not match any attr\n", col->name);
            rtn = false;
        }
        col = col->next;
        vals_nd = vals_nd->next;
        }
    } else {
        int i = 0;
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
                            printf("error: varchar len is too long\n");
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
                } else {
                    if (attr_nd->value) 
                        free(attr_nd->value);
                    free(attr_nd);
                    attr_nd = NULL;
                }
            }
            vals_nd = vals_nd->next;
        }
    }

    if (rtn && attr_head) {
        tuple_nd = (tuple_t *) malloc(sizeof(tuple_t));
        if (!tuple_nd) {
            printf("no heap mem\n");
            // free all the attr node just created;
            //
        }
        tuple_nd->attr = attr_head;
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
        //free all the attr node just created
    }

    return rtn;
}

stmt_node_t *sql_insert_stmt_create(stmt_type_e stmt_type, char *table_name, col_node_t *col_name_list, insert_vals_node_t *insr_vals_list)
{
   
    stmt_node_t *stmt_nd = NULL;
    insert_stmt_t *insr_stmt = NULL;
    stmt_nd = sql_stmt_act_init();
    if (!stmt_nd) {
        printf("no heap mem\n");
        return NULL;
    }
    insr_stmt = (insert_stmt_t *) malloc(sizeof(insert_stmt_t));
    if (!insr_stmt) {
        printf("no heap mem\n");
        free(stmt_nd);
        return NULL;
    }
    insr_stmt->table_name = strdup(table_name);
    insr_stmt->col_list = col_name_list;
    insr_stmt->insr_vals_list = insr_vals_list;
    (stmt_nd->stmt_save)(stmt_nd, stmt_type, (void *)insr_stmt);
    return stmt_nd;
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
        free(vals_prev->var_info->varchar_value);
        free(vals_prev->var_info);
        free(vals_prev);

    }
    free(insr_stmt->table_name);
    free(insr_stmt);
}

bool sql_insert_stmt_handle(insert_stmt_t *insr_stmt)
{
    bool rtn = true;
    create_table_node_t *table = sql_find_table(insr_stmt->table_name);
    if (table) {
        if (insr_stmt->col_list) {
            if (!sql_check_prikey_exist(table, insr_stmt->col_list)) {
                printf("error: miss the primary key(s)\n ");
                rtn = false;
            }
        }
        if (rtn && !sql_data_info_valid_chk(table, insr_stmt->col_list, insr_stmt->insr_vals_list)) {
            printf("error: error in data input\n");
            rtn = false;
        }
    }
    else {
        printf("error: fails to find the table for table name: %s\n", insr_stmt->table_name);
        rtn = false;   
    }
    sql_output_insert_result_to_file(insr_stmt);
    sql_insert_stmt_free_mem(insr_stmt);
    return rtn;
    // check if NOT-NULL attr is NULL
}

void sql_stmt_handle(stmt_node_t *stmt)
{
    switch(stmt->type)
    {
    case STMT_TYPE_INSERT_TUPLE:
        sql_insert_stmt_handle((insert_stmt_t *)(stmt->stmt_info));
        break;
    default:
        printf("invalid stmt\n");
        break;
    }
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
    memset(table, 0, sizeof(create_table_node_t));
    table->table_name = strdup(table_name);
    if (!table->table_name) {
        return NULL;
    }
    table->prim_key_num = 0;
    table->prim_key_attr = NULL;
    table->tuple_list_head = NULL;
    table->tuple_list_tail = NULL;
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
    if (!data)
        return NULL;
    switch(type) 
    {
        case DATA_TYPE_INT:
            data->int_value = int_val;
            break;
        case DATA_TYPE_VARCHAR:
            data->varchar_value = strdup(varchar_val);
            data->varchar_len = strlen(varchar_val);
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

void sql_output_insert_result_to_file(insert_stmt_t *insr_stmt)
{

    create_table_node_t *table = sql_find_table(insr_stmt->table_name);
    if (table) {
        printf("table name: %s\n", table->table_name);
        int i = 0;
        for (i = 0; i < table->attr_num; i++) {
            printf("\t%s", table->attr[i]->header->name);
            if(table->attr[i]->header->is_PRIKEY)
                printf("(P)");
        }
        printf("\n");
        if (table->tupleNum) {
            tuple_t *tuple_nd = NULL;
            tuple_nd = table->tuple_list_head;
            while (tuple_nd) {
                attr_node_t *attr_nd = tuple_nd->attr; 
                while (attr_nd && attr_nd->value) {
                    
                    if(attr_nd->header->data_type == DATA_TYPE_VARCHAR ) // TODO: may not be right
                        printf("\t\"%s\"", attr_nd->value->varchar_value);
                    else
                        printf("\t%d", attr_nd->value->int_value);
                    attr_nd = attr_nd->next;
                } 
                tuple_nd = tuple_nd->next;
                printf("\n");
            }
        }
    }
}

