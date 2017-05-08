#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashIdx.h"
#include "index.h"

#define EH_OK 87

int db_hash_idx_craete(const char *name){
    struct index *hash_idx;
    //hash_idx = indexNew(name);
    //indexDump(hash_idx);
    if(hash_idx){
        return EH_OK;
    }
    else{
        return -1;
    }
}

