#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {

    int i = 0;

    if (len > mx_strlen(src)) {
        for (; src[i]; i++)
            dst[i] = src[i];
        for (; dst[i]; i++)
            dst[i] = '\0';
    } else {
        for (; i < len; i++)
            dst[i] = src[i];
    }

    return dst;
}
