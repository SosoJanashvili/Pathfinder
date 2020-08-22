#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {

    unsigned char *p = b;
    unsigned char ch = c;

    for (size_t i = 0; i < len; i++) {
        *(p + i) = ch;
    }

    return b;
}
