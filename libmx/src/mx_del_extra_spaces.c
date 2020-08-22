#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp_str = NULL;
    char *new_str = NULL;
    int temp_str_len;
    int j = 0;

    if (!str)
        return NULL;

    temp_str_len = mx_strlen(str);
    temp_str = mx_strnew(temp_str_len);

    for (int i = 0; str[i]; i++) {
        if (!mx_isspace(str[i]))
            temp_str[j++] = str[i];
        if (!mx_isspace(str[i]) && mx_isspace(str[i + 1]))
            temp_str[j++] = ' ';
    }
    new_str = mx_strtrim(temp_str);
    free(temp_str);
    temp_str = NULL;
    return new_str;
}
