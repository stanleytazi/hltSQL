#ifndef __TREE_IDX_H__
#define __TREE_IDX_H__
#include "bplus.h"

typedef struct {
    int qual_num;
    char *addr[50000];
} tree_range_t;

int db__tree_idx_create(bp_db_t *db, char *name);
int db__tree_idx_sets(bp_db_t *db, char *key, char **value);
int db__tree_idx_gets(bp_db_t *db, const char *key, char **value);
int db__tree_idx_get_range(bp_db_t *db, const char *start, const char *end, void *arg);


#endif



