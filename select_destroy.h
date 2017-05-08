#ifndef _SELECT_DESTROY_
#define _SELECT_DESTROY_
#include "node.h"
void sql_select_stmt_destroy(stmt_node_t *stmtNd);
void sql_select_record_free(sel_rec_t *rec);
void select_record_mapTbl_free(sel_rec_t *rec);
void select_record_attrList_free(sel_rec_t *rec);
void select_record_tplCnn_free(sel_rec_t *rec);
void select_col_list_free(select_col_node_t* select_col_list);
void select_table_list_free(select_table_node_t* select_table_list);
void select_qualifier_free(expr_node_t* select_qualifier);
void var_node_free(var_node_t *var_node);

#endif