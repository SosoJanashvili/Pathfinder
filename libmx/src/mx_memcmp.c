#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {

    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;
    size_t i = 0;

    if (n == 0)
        return 0;

    while (i < n - 1 && p1[i] == p2[i]) {
        i++;
    }

    return p1[i] - p2[i];
}
