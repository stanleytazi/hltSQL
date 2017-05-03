#ifndef __TABLE_H__
#define __TABLE_H__

/*
struct sql_value_s {
    uint32_t     pageNum
    uint32_t     attrNum;
    uint32_t     pkeyNum;
    uint32_t     tupleNum;   
    uint64_t     fileSize;
};

struct sql_attr_s {
    uint32_t    attr_header; // datatype(1 byte) + varchar_len(1byte) + col_attr(2 bytes)
};
*/
int db__table_info_create(table_node_t *tbl);
int db__table_info_write(table_node_t *tbl);
int db__table_info_read(table_node_t *tbl);
int db__table_info_destroy(table_node_t *tbl);

#endif
