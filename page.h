#ifndef __PAGE_H__
#define __PAGE_H__

#define MAX_PAGE_NUM_IN_TABLE 8192 

typedef struct db_page_s db_page_t;
struct db_page_s {
    uint32_t valid_bit:1;
    uint32_t dirty_bit:1;
    uint32_t unused:30;
    void *page;
};

#endif

