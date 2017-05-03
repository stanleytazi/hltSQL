#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include "node.h"
#include "writer.h"
#include "errors.h"
#define DB_PAGE_SIZE 4096
typedef struct db_page_padding_s db_page_padding_t;
struct db_page_padding_s {
    char padding[DB_PAGE_SIZE];
};

int db__table_info_create(table_node_t *tbl)
{
    return bp__writer_create((bp__writer_t *)tbl, tbl->name);
}

int db__table_info_destroy(table_node_t *tbl)
{
    return bp__writer_destroy((bp__writer_t *)tbl);
}
int db__table_info_write(table_node_t *tbl) 
{
    bp__writer_t *w = (bp__writer_t *)tbl;
    char *buff = malloc(sizeof(db_page_padding_t));   
    uint64_t o, psize, offset;
    off_t filesize = 0;
    uint32_t attrNum = tbl->attr_num;
    int i;
    o = 0;
    psize = DB_PAGE_SIZE;
    *(uint32_t *)(buff + o) = 1;
    *(uint32_t *)(buff + o + 4) = htonl(tbl->attr_num);
    *(uint32_t *)(buff + o + 8) = htonl(tbl->pkey_num);
    *(uint32_t *)(buff + o + 12) = htonl(tbl->tuple_num);
    o += 16;
    for (i = 0; i < attrNum; i++) {
        uint8_t type = (tbl->attr[i]->data_type == DATA_TYPE_INT) ? 0 : 1;
        uint32_t hdrInfo = (uint32_t)type|((uint32_t)tbl->attr[i]->varchar_len)<<8|(uint32_t)tbl->attr[i]->col_attr<<16;
        *(uint32_t *)(buff + o) = htonl(hdrInfo);
        uint32_t nameInfo = strlen(tbl->attr[i]->name) + 1;
        *(uint32_t *)(buff + o + 4) = htonl(nameInfo);
        o += 8;
        memcpy(buff+o, tbl->attr[i]->name, nameInfo);
        o += nameInfo;
    }
    bp__writer_write(w, (void *)buff, &offset, &psize);
    free(buff);
    return BP_OK;
}

int db__table_info_read(table_node_t *tbl) 
{
    int ret;
    char *page;
    uint64_t psize = DB_PAGE_SIZE;
    uint64_t o = 0;
    int i;
    uint32_t hdrInfo = 0;
    uint32_t nameLen = 0;
    ret = bp__writer_read((bp__writer_t *)tbl, 0, &psize, (void **)&page);
    if (ret != BP_OK) return ret;

    tbl->attr_num = ntohl(*(uint32_t *)(page + o + 4));
    tbl->pkey_num = ntohl(*(uint32_t *)(page + o + 8));
    tbl->tuple_num = ntohl(*(uint32_t *)(page + o + 12));
    
    o += 16;
    for (i = 0; i < tbl->attr_num; i++) {
        hdrInfo = ntohl(*(uint32_t *)(page + o));
        nameLen = ntohl(*(uint32_t *)(page + o + 4));
        tbl->attr[i] = malloc(sizeof(attr_node_header_t));
        tbl->attr[i]->data_type = (hdrInfo&0x000000FF) ? DATA_TYPE_VARCHAR : DATA_TYPE_INT;
        tbl->attr[i]->varchar_len = (hdrInfo&0x0000FF00) >> 8;
        tbl->attr[i]->col_attr = (hdrInfo&0xFFFF0000) >> 16;
        tbl->attr[i]->name = malloc(nameLen);
        memcpy(tbl->attr[i]->name, page + o + 8, nameLen);
        o = o + 8 + nameLen;
    }

    free(page);
    return BP_OK;
}
