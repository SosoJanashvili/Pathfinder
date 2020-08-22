#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {

    unsigned char *p = dst;
    const unsigned char *p2 = src;
    unsigned char ch = c;
    size_t i = 0;

    while (i < n) {

        p[i] = p2[i];

        if (p[i] == ch) {
            return p + i + 1;
        }

        i++;
    }

    return NULL;
}
