#include "../inc/libmx.h"

static int get_start_index(const char *str) {
    int i = 0;
    for (; mx_isspace(str[i]); i++);
    return i;
}

static int get_end_index(const char *str) {
    int i = mx_strlen(str);
    for (; mx_isspace(str[i - 1]); i--);
    return i;
}

char *mx_strtrim(const char *str) {
    int start;
    int end;
    int new_str_len;
    char *trimmed = NULL;

    if (!str)
        return NULL;

    if (!*str)
        return  mx_strnew(sizeof('\0'));

    start = get_start_index(str);
    end = get_end_index(str);
    new_str_len = end - start;

    if (!(trimmed = mx_strnew(new_str_len)))
        return NULL;

    mx_strncpy(trimmed, &str[start], new_str_len);
    return trimmed;
}
