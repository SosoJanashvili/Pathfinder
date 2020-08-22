#include "../inc/libmx.h"

static char *duplicate_one_string(char const *s1, char const *s2) {

    char *str = NULL;

    if (!s1) {
        str = mx_strdup(s2);
        return str;
    } else {
        str = mx_strdup(s1);
        return str;
    }
}

static char *join_em(char const *s1, char const *s2) {

    char *str = NULL;

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    int j = 0;

    if (!(str = mx_strnew(len1 + len2)))
        return NULL;

    str = mx_strcpy(str, s1);

    for (int i = len1; i < len1 + len2; i++) {
        str[i] = s2[j++];
    }

    return str;
}

char *mx_strjoin(char const *s1, char const *s2) {

    char *str = NULL;

    if (!s1 && !s2)
        return NULL;

    if (!s1 || !s2)
        return duplicate_one_string(s1, s2);

    str = join_em(s1, s2);

    return str;
}
