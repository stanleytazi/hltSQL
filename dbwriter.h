#ifndef _PRIVATE_DBWRITER_H_
#define _PRIVATE_DBWRITER_H_

#include <stdint.h>
#include "./private/writer.h"
#ifdef __cplusplus
extern "C" {
#endif
#define BP_PADDING 64
/*    
#define BP_WRITER_PRIVATE	\
    int fd;                     \
    char *filename;             \
    uint64_t filesize;          \
    char padding[BP_PADDING];

typedef struct bp__writer_s bp__writer_t;
typedef int (*bp__writer_cb)(bp__writer_t *w, void *data);

enum comp_type {
    kNotCompressed = 0,
    kCompressed = 1
};
*/
int db__writer_create(bp__writer_t *w, const char *filename);
int db__writer_destroy(bp__writer_t *w);

int db__writer_fsync(bp__writer_t *w);

int db__writer_compact_name(bp__writer_t *w, char **compact_name);
int db__writer_compact_finalize(bp__writer_t *s, bp__writer_t *t);

int db__writer_read(bp__writer_t *w,
                    const uint64_t offset,
                    uint64_t *size,
                    void **data);
int db__writer_write(bp__writer_t *w,
                     const void *data,
                     uint64_t *offset,
                     uint64_t *size);

int db__writer_pwrite(bp__writer_t *w,
                      const uint64_t offset,
                      uint64_t *size,
                      void *data);

int db__writer_find(bp__writer_t *w,
                    const enum comp_type comp,
                    const uint64_t size,
                    void *data,
                    bp__writer_cb seek,
                    bp__writer_cb miss);
/*
struct bp__writer_s {
    BP_WRITER_PRIVATE
};
*/
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _PRIVATE_WRITER_H_ */
