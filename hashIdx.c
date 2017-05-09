#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashIdx.h"




int db__hash_idx_craete(char *name){
    struct index *hash_idx;
    hash_idx = indexNew(name);
    if(hash_idx){
        return EH_OK;
    }
    else{
        return -1;
    }
}


int db__hash_idx_sets(char *Idxname, char *key, int value){
    struct index *hash_idx = NULL;
    hash_idx = indexLoad(Idxname);
    int ret;
    if(hash_idx==NULL){
        printf("can't find the hash index : %s\n", Idxname);
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
    return ret;
}


int db__hash_idx_gets(){
    
}
