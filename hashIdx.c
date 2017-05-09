#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashIdx.h"




int db__hash_idx_craete(char *name){
    struct index *hash_idx;
    hash_idx = indexNew(name);
    if(hash_idx){
        indexDump(hash_idx);
        indexFree(hash_idx);//
        printf("create hash index %s:succeed\n", name);
        return EH_OK;
    }
    else{
        printf("create hash index %s:failed\n", name);
        return -1;
    }
}


int db__hash_idx_sets(char* fileName, char *key, int value){
    struct index *hash_idx = NULL;// hash index pointer
    hash_idx = indexLoad(fileName);
    int ret;
    if(hash_idx==NULL){
        printf("can't find the hash index in db__hash_idx_sets()\n");
        return -1;
    }
    else{
        if(!indexInsert(hash_idx, key, value, 0.0001)){
            printf("insert to hash index fail :key=%s, value=%d\n", key, value);
            return -1;
        }
        else{
            printf("insert to hash index succeed\n");
        }
    }
    ret = EH_OK;
    indexDump(hash_idx);// write index data to disk
    indexFree(hash_idx);// free hash index in mem
    return ret;
}


int db__hash_idx_gets(const char *fileName, const char *key, unsigned int **value)
{
    struct index *idx;
	struct result *result;
	unsigned int num;
	int i;

	idx = indexLoad(fileName);
	if(idx == NULL){
	    printf("file not found:  %s \n", fileName);
		return -1;
	}

	result = indexFind(idx, key,&num);
	*value = malloc(sizeof(unsigned int) * num*2);
	if(result)
	{
	    printf("Find %d tuples\n", num);
		for(i=0; i<num; i++)
		{
		    (*value)[i*2] = result[i].d/10000;
		    (*value)[i*2 +1] = result[i].d%10000;
		    printf("tuple %d : %d-> (%d, %d) \n",i , result[i].d, (*value)[i*2], (*value)[i*2 +1]);
		    assert((*value)[i*2 +1] < 4096);
		}
		free(result);
	}
	indexFree(idx);
	return num*2;
}
