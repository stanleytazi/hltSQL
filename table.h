#ifndef __TABLE_H__
#define __TABLE_H__
#define PAGE_TYPE_DATABASE   0x00A1
#define PAGE_TYPE_TBL_SCHEMA 0x00A2
#define PAGE_TYPE_TBL_HEADER 0x00A3
#define PAGE_TYPE_TUPLE      0x00A4

/*
disk memory layout
struct sql_value_s {
    
    uint16_t     pageType;
    uint16_t     pageOffest;
    uint32_t     pageNum
    uint32_t     attrNum;
    uint32_t     pkeyNum;
    uint32_t     tupleNum;   
    uint32_t     fileSize;
    struct sql_attr_s attr[0];
};

struct sql_attr_s {
    uint32_t    attr_header; // datatype(1 byte) + varchar_len(1byte) + col_attr(2 bytes)
};
*/
typedef struct db_db_s db_db_t;
typedef struct db_tbl_name_s db_tbl_name_t;
struct db_tbl_name_s {
    char *name;
    uint64_t type;
};

struct db_db_s {
    BP_WRITER_PRIVATE
    db_tbl_name_t tbl[MAX_TABLE_ENTRY];
    uint64_t tbl_num;
};

int db__table_info_create(table_node_t *tbl);
int db__table_info_write(table_node_t *tbl);
int db__table_info_read(table_node_t *tbl);
int db__table_info_destroy(table_node_t *tbl);
int db__dbms_info_init(db_db_t *db);
int db__dbms_info_create(db_db_t *db, char *name);
int db__dbms_info_table_write(db_db_t *db, table_node_t *tbl);
int db__dbms_info_table_try_read(db_db_t *db);

#endif
