#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeIdx.h"

int db__tree_idx_create(bp_db_t *db, char *name)
{
    int ret = bp_open(db, name);
    return ret;
}

//example: value = ", address"
int db__tree_idx_sets(bp_db_t *db, char *key, char **value)
{
    char *value1 = NULL;
    char *kVal;
    int ret;
    bp_gets(db, key, &value1);
    
    if (value1) {
        size_t size = strlen(*value) + strlen(value1) + 2;
        char *value2;    
        value2 = realloc(*value, size);
        strcat(value2, value1);
        kVal = value2;
        *value = value2;
    } else {
        kVal = *value;
    }
    ret = bp_sets(db, key, kVal);
    return ret;
}

int db__tree_idx_gets(bp_db_t *db, const char *key, char **value)
{
    return bp_gets(db, key, value);
}


void range_cb(void* arg, const bp_key_t* key, const bp_value_t* value) 
{
    tree_range_t *range = (tree_range_t *)arg; 
    char *save;
    if (value && value->value) {
        save = malloc(value->length + 1);
        memcpy(save, value->value, value->length + 1);
        range->addr[range->qual_num] = save;
        range->qual_num++;
    }
}

int db__tree_idx_get_range(bp_db_t *db, const char *start, const char *end, void *arg)
{
    return bp_get_ranges(db, start, end, range_cb, arg);
}

