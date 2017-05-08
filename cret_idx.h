#ifndef __CRET_IDX_H__
#define __CRET_IDX_H__

typedef struct cret_idx_stmt_s {
    char *tblName;
    col_node_t *idxName;
    col_node_t *col_list;
} cret_idx_stmt_t;

stmt_node_t *sql_cret_index_stmt_create(char *tblName, col_node_t *idxName, col_node_t *col_name_list);
#endif 
