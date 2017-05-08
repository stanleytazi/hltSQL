#include <stdlib.h>
#include "node.h"
#include "cret_idx.h"

stmt_node_t *sql_cret_index_stmt_create(char *tblName, col_node_t *idxName, col_node_t *col_name_list)
{
    cret_idx_stmt_t *idxStmt = CALLOC_MEM(cret_idx_stmt_t, 1);
    CALLOC_CHK(idxStmt);

    idxStmt->tblName = tblName;
    idxStmt->idxName = idxName;
    idxStmt->col_list = col_name_list;
    
    stmt_node_t *stmtNd = sql_stmt_act_init();
    stmtNd->stmt_save(stmtNd, STMT_TYPE_CREATE_INDEX, (void *)idxStmt);
    return stmtNd;

}

