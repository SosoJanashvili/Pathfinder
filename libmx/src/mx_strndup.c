#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *str = NULL;
    size_t len;

    if (!s1)
        return NULL;

    if (!*s1) {
        if (!(str = mx_strnew(sizeof('\0'))))
            return NULL;
        return str;
    }
    len = (size_t)mx_strlen(s1) < n ? (size_t)mx_strlen(s1) : n;

    if (!(str = mx_strnew(len)))
        return NULL;

    if (!(str = mx_strncpy(str, s1, len)))
        return NULL;

    return str;
}
