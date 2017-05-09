#ifndef __HASH_IDX_H__
#define __HASH_IDX_H__
#include "index.h"

#define EH_OK 87

int db__hash_idx_craete(char *name);
int db__hash_idx_sets(char* fileName, char *key, int value);
int db__hash_idx_gets(const char *fileName, const char *key, unsigned int **value);






#endif
