#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {

    int len;

    len = mx_strlen(s);

    for (int i = 0; i <= len; i++) {
        if (s[i] == c)
            return (char *)&s[i];
    }

    return NULL;
}
