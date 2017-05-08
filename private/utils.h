#ifndef _PRIVATE_UTILS_H_
#define _PRIVATE_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* uint64_t */

uint64_t bp__compute_hashl(uint64_t key);
uint64_t hhtonll(uint64_t value);
uint64_t nntohll(uint64_t value);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _PRIVATE_UTILS_H_ */
