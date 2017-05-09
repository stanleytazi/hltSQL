#include "select_destroy.h"
#include <stdlib.h>
void  sql_select_stmt_destroy(stmt_node_t *stmtNd)
{
   
    select_stmt_t *selectStmt = (select_stmt_t *)stmtNd->stmt_info;
    select_col_list_free(selectStmt->select_col_list);
    select_table_list_free(selectStmt->select_table_list);
    select_qualifier_free(selectStmt->select_qualifier);
    
}
void select_col_list_free(select_col_node_t* select_col_list)
{
    select_col_node_t* tmp = select_col_list;
    while(tmp != NULL){
        select_col_node_t* f = tmp;
        tmp = tmp->next;
        if(f->is_prefix_dot_star){
            free(((var_node_t*)(select_col_list->col_info))->prefix_value);
            free(f);
        }
        else {
            if(f->alias_name) free(f->alias_name);
            if(!f->is_star){
               if(f->is_aggregation){
                   if(((aggregation_node_t*)(f->col_info))->attr_info != NULL) var_node_free(((aggregation_node_t*)(f->col_info))->attr_info);
                   free(f->col_info);
               }
               else var_node_free((var_node_t *)(f->col_info));
            }
            free(f);
        }
    }
}
void var_node_free(var_node_t *var_node)
{
    switch(var_node->type) 
    {
        case DATA_TYPE_INT:
            break;
        case DATA_TYPE_VARCHAR:
            free(var_node->varchar_value);
            break;
        case DATA_TYPE_NAME:
            free(var_node->varchar_value);
            break;
        //0401
        case DATA_TYPE_PREFIX:
            free(var_node->varchar_value);
            free(var_node->prefix_value);
            break;
        default:
            break;
    }
    free(var_node);
}

void select_table_list_free(select_table_node_t* select_table_list)
{
    select_table_node_t* tmp = select_table_list;
    while(tmp != NULL){
        select_table_node_t* f = tmp;
        tmp = tmp->next;
        if(f->alias_name != NULL) free(f->alias_name);
        var_node_free(f->table_info);
        free(f);
    }
}
void select_qualifier_free(expr_node_t* select_qualifier)
{
    expr_node_t* tmp = select_qualifier;
    while(tmp != NULL){
        expr_node_t* f = tmp;
        tmp = tmp->next;
        if(f->type == EXPR_TYPE_LOGIC) {
            if( ((logic_node_t*)(f->expr_info))->left->type == EXPR_TYPE_COMPARISON) {
                var_node_free(((comparison_node_t*)(((logic_node_t*)(f->expr_info))->left->expr_info))->left);
                var_node_free(((comparison_node_t*)(((logic_node_t*)(f->expr_info))->left->expr_info))->right);
                free( ((logic_node_t*)(f->expr_info))->left );
            }
            else var_node_free( (var_node_t *)(((logic_node_t*)(f->expr_info))->left->expr_info) );
            
            if( ((logic_node_t*)(f->expr_info))->right->type == EXPR_TYPE_COMPARISON) {
                var_node_free(((comparison_node_t*)(((logic_node_t*)(f->expr_info))->right->expr_info))->left);
                var_node_free(((comparison_node_t*)(((logic_node_t*)(f->expr_info))->right->expr_info))->right);
                free( ((logic_node_t*)(f->expr_info))->right );
            }
            else var_node_free( (var_node_t *)(((logic_node_t*)(f->expr_info))->right->expr_info) );
        }
        else if(f->type == EXPR_TYPE_COMPARISON){
            var_node_free(((comparison_node_t*)(f->expr_info))->left);
            var_node_free(((comparison_node_t*)(f->expr_info))->right);
        }
        var_node_free(f->expr_info);
        free(f);
    }
    
}

void sql_select_record_free(sel_rec_t *rec)
{
    select_record_mapTbl_free(rec); // rec ->mptbl -> next.... free
    select_record_attrList_free(rec); // output_Name free 
    select_record_tplCnn_free(rec); // rec -> head -> next..... free
    free(rec->cmpJoin);
}

void select_record_mapTbl_free(sel_rec_t *rec)
{
    map_table_name_t *tmp = rec->mapTbl;
    while(tmp != NULL){
        map_table_name_t *f = tmp;
        tmp = tmp->next;
        free(f);
    }
}

void select_record_attrList_free(sel_rec_t *rec)
{
    sel_attr_t* tmp = rec->attr_list;
    while(tmp != NULL){
        sel_attr_t* f = tmp;
        tmp = tmp->next;
        //if(f->output_Name != NULL) free(f->output_Name);
        free(f);
    }
}

void select_record_tplCnn_free(sel_rec_t *rec)
{
    tuple_cnn_t *tmp = rec->head;
    while(tmp != NULL){
        tuple_cnn_t *f = tmp;
        tmp = tmp->next;
        free(f);
    }
}