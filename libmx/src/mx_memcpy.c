#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {

    unsigned char *p = dst;
    const unsigned char *p2 = src;

    for (size_t i = 0; i < n; i++) {
        p[i] = p2[i];
    }

    return dst;
}
