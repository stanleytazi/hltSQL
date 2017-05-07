#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>
#include "node.h"
#include "dbwriter.h"
#include "table.h"
#include "./private/errors.h"


typedef struct db_page_padding_s db_page_padding_t;
struct db_page_padding_s {
    char padding[DB_PAGE_SIZE];
};
char zeroPadding[64] = {0};

int db__table_info_create(table_node_t *tbl)
{
    return db__writer_create((bp__writer_t *)tbl, tbl->name);
}

int db__table_info_destroy(table_node_t *tbl)
{
    return db__writer_destroy((bp__writer_t *)tbl);
}
int db__table_info_write(table_node_t *tbl) 
{
    char *buff = malloc(sizeof(db_page_padding_t));   
    char *tblInfo = buff + DB_PAGE_HEADER_SIZE;
    uint64_t o, psize, offset;
    off_t filesize = 0;
    uint32_t attrNum = tbl->attr_num;
    uint16_t pageHdrSize = DB_PAGE_HEADER_SIZE;
    int i;
    o = 0;
    psize = DB_PAGE_SIZE;
    *(uint32_t *)(tblInfo + o) = 1;
    *(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_ATTR_NUM) = htonl(tbl->attr_num);
    *(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_PKEY_NUM) = htonl(tbl->pkey_num);
    *(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_TUPLE_NUM) = htonl(tbl->tuple_num);
    o += TBL_INFO_OFFSET_ATTR_INFO;
    for (i = 0; i < attrNum; i++) {
        uint8_t type = (tbl->attr[i]->data_type == DATA_TYPE_INT) ? 0 : 1;
        uint32_t hdrInfo = (uint32_t)type
                            | ((uint32_t)tbl->attr[i]->varchar_len) << 8
                            | (uint32_t)tbl->attr[i]->col_attr << 16;
        *(uint32_t *)(tblInfo + o) = htonl(hdrInfo);
        uint32_t nameInfo = strlen(tbl->attr[i]->name) + 1;
        *(uint32_t *)(tblInfo + o + 4) = htonl(nameInfo);
        o += 8;
        memcpy(tblInfo + o, tbl->attr[i]->name, nameInfo);
        memcpy(tblInfo + o + nameInfo, zeroPadding, sizeof(zeroPadding) - nameInfo);
        o += sizeof(zeroPadding); //
    }
    uint16_t pageType = PAGE_TYPE_TBL_HEADER;
    *(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_TYPE) = htons(pageType);
    *(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_OFFSET) = htons((pageHdrSize + o));
    db__writer_write((bp__writer_t *)tbl, (void *)buff, &offset, &psize);
    tbl->pageTable[0].valid_bit = 1;
    tbl->pageTable[0].page = buff;
    tbl->curr_page = 0;
    return BP_OK;
}

int db__table_info_read(table_node_t *tbl) 
{   
    int ret;
    char *page;
    char *tblInfo;
    uint64_t psize = DB_PAGE_SIZE;
    uint64_t o = 0;
    int i;
    uint32_t hdrInfo = 0, nameLen = 0;
    uint16_t pageType;
    ret = db__writer_read((bp__writer_t *)tbl, 0, &psize, (void **)&page);
    if (ret != BP_OK) return ret;
    
    pageType = ntohs(*(uint16_t *)page);
    assert(pageType == PAGE_TYPE_TBL_HEADER);

    tblInfo = page + DB_PAGE_HEADER_SIZE;
    
    tbl->curr_page = ntohl(*(uint32_t *)(tblInfo + o )) - 1;
    tbl->attr_num = ntohl(*(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_ATTR_NUM));
    tbl->pkey_num = ntohl(*(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_PKEY_NUM));
    tbl->tuple_num = ntohl(*(uint32_t *)(tblInfo + o + TBL_INFO_OFFSET_TUPLE_NUM));
    
    o += TBL_INFO_OFFSET_ATTR_INFO;
    for (i = 0; i < tbl->attr_num; i++) {
        hdrInfo = ntohl(*(uint32_t *)(tblInfo + o));
        nameLen = ntohl(*(uint32_t *)(tblInfo + o + 4));
        tbl->attr[i] = sql_attr_header_node_create_and_init(NULL);
        tbl->attr[i]->data_type = (hdrInfo&0x000000FF) ? DATA_TYPE_VARCHAR : DATA_TYPE_INT;
        tbl->attr[i]->varchar_len = (hdrInfo&0x0000FF00) >> 8;
        tbl->attr[i]->col_attr = (hdrInfo&0xFFFF0000) >> 16;
        tbl->attr[i]->name = malloc(nameLen);
        memcpy(tbl->attr[i]->name, tblInfo + o + 8, nameLen);
        o = o + 8 + sizeof(zeroPadding);
    }

    free(page);
    return BP_OK;
}



#define DB_TABLE_TYPE_TABLE 0x00B0
#define DB_TABLE_TYPE_INDEX 0x00B1
#define DB_TABLE_TYPE_TEMP  0x00B2

int db__dbms_info_create(db_db_t *db, char *name)
{
    db__writer_create((bp__writer_t *)db, name);
    if (db__dbms_info_table_try_read(db) != BP_OK) {
        db__dbms_info_init(db);
    }
    return BP_OK;
}

int db__dbms_info_destroy(db_db_t *db)
{
    return db__writer_destroy((bp__writer_t *)db);
}

int db__dbms_info_init(db_db_t *db)
{
    char *buff = calloc(1, DB_PAGE_SIZE);
    int ret;
    uint64_t offset = 0;
    uint64_t psize = DB_PAGE_SIZE;
    *(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_TYPE) = PAGE_TYPE_DATABASE;
    *(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_OFFSET) = DB_PAGE_HEADER_SIZE + 8;
    
    ret = db__writer_pwrite((bp__writer_t *)db, offset, &psize, buff);
    free(buff);
    if (ret != BP_OK) return ret;
    
    return BP_OK;
    //return bp__writer_write((bp__writer_t *)db, (void *)buff, &offset, &psize);
}

int db__dbms_info_table_try_read(db_db_t *db)
{
    char *buff, *info;
    uint64_t rsize, tblNum, o;
    uint16_t pageType;
    uint32_t nameLen;
    int ret, i;

    rsize = DB_PAGE_SIZE;
    ret = db__writer_read((bp__writer_t *)db, 0, &rsize, (void **)&buff);
    if (ret != BP_OK) return ret;
    
    pageType = *(uint16_t *)buff;
    assert(pageType == PAGE_TYPE_DATABASE 
            && (*(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_OFFSET) != 0));
    tblNum = *(uint64_t *)(buff + DB_PAGE_HEADER_SIZE);
    nameLen = 0;
    o = DB_PAGE_HEADER_SIZE + 8;
    for (i = 0; i < tblNum; i++) {
        nameLen = strlen((char *)(buff + o)) + 1;
        db->tbl[i].name = malloc(nameLen);
        memcpy(db->tbl[i].name, buff + o, nameLen);
        db->tbl[i].type = *(uint64_t *)(buff + o + 8);
        o += 16;
    }
    db->tbl_num = tblNum;
    free(buff);
    return BP_OK;
}

int db__dbms_info_table_write(db_db_t *db, table_node_t *tbl)
{
    char *buff, *info;   
    uint64_t tblNum, psize, o, offset = 0;
    uint32_t nameLen;
    uint16_t pageType;
    int i, ret;
    psize = DB_PAGE_SIZE;
    ret = db__writer_read((bp__writer_t *)db, 0, &psize, (void **)&buff);
    if (ret != BP_OK) return ret;
    pageType = *(uint16_t *)buff;
    assert(pageType == PAGE_TYPE_DATABASE 
            && (*(uint16_t *)(buff + DB_PAGE_HEADER_OFFSET_OFFSET) != 0));
    o = DB_PAGE_HEADER_SIZE;
    tblNum = *(uint64_t *)(buff + o);
    o += (8+tblNum*16);
    nameLen = strlen(tbl->name) + 1;
    memcpy(buff + o, tbl->name, nameLen) ;
    memcpy(buff + o + nameLen, zeroPadding, sizeof(zeroPadding) - nameLen);
    db->tbl[tblNum].name = malloc(nameLen);
    strcpy(db->tbl[tblNum].name, tbl->name);
    db->tbl[tblNum].type = DB_TABLE_TYPE_TABLE;
    tblNum++;
    *(uint64_t *)(buff + DB_PAGE_HEADER_SIZE) = tblNum;
    db->tbl_num = tblNum;
    db__writer_pwrite((bp__writer_t *)db, offset, &psize, buff);
    free(buff);
    return BP_OK;
}

#define MAX_TUPLE_INFO_BYTE 512

int db__page_tuple_info_packed(table_node_t *tbl, tuple_t *tuple, uint16_t *size, void **buff)
{
    char *pack = malloc(MAX_TUPLE_INFO_BYTE);
    uint16_t tupleLen = 0;
    uint8_t dataLen = 0;
    uint16_t attrBmp = 0;
    attr_node_t *attr;
    uint64_t o;
    int i;

    o = 4;
    for (i = 0; i < tbl->attr_num; i++) {
        attr = tuple->find_attr_vals(tuple, tbl->attr[i]->name);
        if (!attr) continue;
        if (attr->header->data_type == DATA_TYPE_INT) {
            dataLen = sizeof(int);
            memcpy(pack + o + 1, &attr->value->int_value, dataLen);
            dataLen = dataLen << 1 | 1;
        } else {
            dataLen = strlen(attr->value->varchar_value) + 1;
            memcpy(pack + o + 1, attr->value->varchar_value, dataLen);
            dataLen = dataLen << 1 | 0;
        }
        *(uint8_t *)(pack + o) = dataLen;
        o += ((dataLen >> 1) + 1);
        attrBmp |= (1<<i);
    }
    *size = o;
    *(uint16_t *)pack = attrBmp;
    *(uint16_t *)(pack + 2) = o;
    *buff = pack;  
    
    return BP_OK;
}

int db__page_tuple_info_unpacked(table_node_t *tbl, tuple_t *tuple, uint16_t *offset, char *buff)
{
    uint16_t attrBmp, tupleSize, o;
    uint8_t config, size;
    attr_node_t *attrNd = NULL; 
    attr_node_t *attrNdPrev = NULL; 
    attr_node_t *attrHd = NULL; 
    var_node_t *vals;
    char *unpack = buff + *offset;
    int i;
    
    attrBmp = *(uint16_t *)unpack;
    tupleSize = *(uint16_t *)(unpack + 2);
    o = 4;
    for (i = 0; i < tbl->attr_num && attrBmp&(1<<i); i++) {
        config = *(uint8_t *)(unpack + o);
        vals = CALLOC_MEM(var_node_t, 1);
        CALLOC_CHK(vals);
        size = (config >> 1);
        if (config & 0x0001) {
            vals->type = DATA_TYPE_INT;
            vals->int_value = *(int *)(unpack + o + 1);
        } else {
            vals->type = DATA_TYPE_VARCHAR;
            vals->varchar_value = malloc(size);
            memcpy(vals->varchar_value, unpack + o + 1, size);
        }
        attrNd = sql_attr_node_create_and_init(tbl->attr[i]);
        attrNd->set_value(attrNd, vals);
        o += (size + 1);
        assert(o <= tupleSize);
        if (attrHd) {
            attrNdPrev->next = attrNd;
            attrNdPrev = attrNd;
        } else {
            attrNdPrev = attrNd;
            attrHd = attrNd;
        }
    }
    tuple->add_attr_vals(tuple, attrHd);
    *offset += tupleSize;
    return BP_OK;
}

int db__table_info_page_write(table_node_t *tbl, const uint16_t pageId, void *page)
{
    uint64_t psize, offset;
    int ret;
    psize = DB_PAGE_SIZE;
    offset = pageId * DB_PAGE_SIZE;
    ret = db__writer_pwrite((bp__writer_t *)tbl, offset, &psize, page);
 
    return ret;
}

int db__table_info_all_pages_write(table_node_t *tbl)
{
    int i, ret = BP_OK;;
    for (i = 0; i <= tbl->curr_page; i++) {
        if (tbl->pageTable[i].dirty_bit) {
            ret = db__table_info_page_write(tbl, i, tbl->pageTable[i].page);
            if (ret != BP_OK) break;
        }
    }
    return ret;
}

int db__table_info_update(table_node_t *tbl)
{
    char *page = (char *)(tbl->pageTable[0].page);
    char *tblInfo = page + DB_PAGE_HEADER_SIZE;
    
    *(uint32_t *)(tblInfo) = htonl(tbl->curr_page + 1);
    *(uint32_t *)(tblInfo + TBL_INFO_OFFSET_ATTR_NUM) = htonl(tbl->attr_num);
    *(uint32_t *)(tblInfo + TBL_INFO_OFFSET_PKEY_NUM) = htonl(tbl->pkey_num);
    *(uint32_t *)(tblInfo + TBL_INFO_OFFSET_TUPLE_NUM) = htonl(tbl->tuple_num);
    tbl->pageTable[0].dirty_bit = 1;
    
    return BP_OK;
}

int db__table_info_tuple_save_in_mem(table_node_t *tbl, tuple_t *tuple) 
{
    char *tupleInfo;
    uint16_t tupleSize, pageOffset;
    char *page = (char *)(tbl->pageTable[tbl->curr_page].page);
    
    db__page_tuple_info_packed(tbl, tuple, &tupleSize, (void **)&tupleInfo);
    assert(page != NULL);
    
    pageOffset = *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_OFFSET);
    if ( (pageOffset + tupleSize) > DB_PAGE_SIZE) {
        db__table_info_page_write(tbl, tbl->curr_page, page);
        tbl->curr_page++;
        tbl->pageTable[tbl->curr_page].valid_bit = 1;
        page = calloc(1, DB_PAGE_SIZE);
        *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_TYPE) = PAGE_TYPE_TUPLE;
        pageOffset = DB_PAGE_HEADER_SIZE;
        tbl->pageTable[tbl->curr_page].page = page;
    }
    tuple->pageId = tbl->curr_page;
    tuple->offset = pageOffset + tupleSize;
    memcpy(page + pageOffset, tupleInfo, tupleSize);
    *(uint16_t *)(page + DB_PAGE_HEADER_OFFSET_OFFSET) = pageOffset + tupleSize;
    tbl->pageTable[tbl->curr_page].dirty_bit = 1;
    
    free(tupleInfo);
    return BP_OK;
}

int db__table_info_page_read(table_node_t *tbl, const uint16_t pageId, void **page)
{
    uint64_t psize, offset;
    int ret;
    psize = DB_PAGE_SIZE;
    offset = pageId * DB_PAGE_SIZE;
    ret = db__writer_read((bp__writer_t *)tbl, offset, &psize, page);
 
    return ret;
}
int db__table_info_page_fault_hdl(table_node_t *tbl, uint16_t id, char **page)
{
    int ret; 
    ret = db__table_info_page_read(tbl, id, (void **)page);
    if (ret != BP_OK) return ret;
    tbl->pageTable[id].page = *page;
    tbl->pageTable[id].valid_bit = 1;
    return BP_OK;
}

int db__table_info_all_pages_read(table_node_t *tbl)
{
    char *page;
    uint64_t psize, offset;
    uint16_t pageNum;
    int i, ret;
    psize = DB_PAGE_SIZE;
    ret = db__writer_read((bp__writer_t *)tbl, 0, &psize, (void **)&page);
    if (ret != BP_OK) return ret;

    tbl->pageTable[0].page = page;
    tbl->pageTable[0].valid_bit = 1;

    pageNum = ntohl(*(uint32_t *)(page + DB_PAGE_HEADER_SIZE));
    assert(tbl->curr_page <= pageNum);

    for (i = 1; i < pageNum; i++) {
        ret = db__table_info_page_fault_hdl(tbl, i, (char **)&page);
        /*ret = db__table_info_page_read(tbl, i, (void **)&page);
        if (ret != BP_OK) return ret;
        tbl->pageTable[i].page = page;
        tbl->pageTable[i].valid_bit = 1;*/
    }
    return BP_OK;
}

/*
int db__dbms_info_table_read(db_db_t *db) 
{
    
}*/
