#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {

    if (!s1 || !s2)
        return NULL;

    int len1 = mx_strlen(s1);
    int i = 0;

    for (; s2[i] != '\0'; i++) {
        s1[len1 + i] = s2[i];
    }

    s1[len1 + i] = '\0';

    return s1;
}
