#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeIdx.h"

void range_cb(void* arg, const bp_key_t* key, const bp_value_t* value);
int db__tree_idx_create(bp_db_t *db, char *name)
{
    int ret = bp_open(db, name);
    return ret;
}

int updates_cb(void* arg, const bp_value_t* previous,  bp_value_t* curr) {
  //char* expected = (char*) arg;
  char *valTmp;
  size_t size = strlen(curr->value) + strlen(previous->value) + 2;
  valTmp = realloc(curr->value, size);
  strcat(valTmp, previous->value);
  curr->value = valTmp;
  printf("newCurr%s, old=%s\n", valTmp, previous->value);
  //assert(strcmp(previous->value, expected) == 0);
  return 1;
}

static int bp__strcmp_compare_cb(const bp_key_t *a, const bp_key_t *b)
{
    int res = strcmp(a->value, b->value);
    return res;
}

static int bp__numcmp_compare_cb(const bp_key_t *a, const bp_key_t *b)
{
    int num_a, num_b;
    sscanf(a->value, "%d", &num_a);
    sscanf(b->value, "%d", &num_b);
    if (num_a >= num_b)
        return 1;
    else
        return -1;
}

void db__tree_set_str_compare_cb(bp_db_t *db)
{
    bp_set_compare_cb(db, bp__strcmp_compare_cb);
}

void db__tree_set_num_compare_cb(bp_db_t *db)
{
    bp_set_compare_cb(db, bp__numcmp_compare_cb);
}
//example: value = ", address"
int db__tree_idx_sets(bp_db_t *db, char *key, char **value)
{
    char *value1 = NULL;
    char *kVal;
    int ret;
    tree_range_t range; 
    range.qual_num = 0;
    bp_get_ranges(db, key, key, range_cb,  &range);
    value1 = range.addr[0];
    printf("after bp_gets: key= %s, value=%s\n",key, value1);
    
    /*if (value1) {
        size_t size = strlen(*value) + strlen(value1) + 2;
        char *value2;    
        value2 = realloc(*value, size);
        strcat(value2, value1);
        printf("after strcat %s\n", value2);
        kVal = value2;
        *value = value2;
    } else {
        kVal = *value;
    }
    printf("key=%s, kVal=%s\n ", key, kVal);
    ret = bp_sets(db, key, kVal);
    bp_fsync(db);
    */
    ret = bp_updates(db, key, *value, updates_cb, (void *)&range);
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

