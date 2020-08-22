//
// Created by Soso Janashvili on 17.08.2020.
//

#include "../inc/libmx.h"

char *mx_strsub(char const *s, unsigned int start, size_t len) {

    char *substr = NULL;
    size_t i = 0;

    if (!s)
        return (NULL);

    if (!(substr = mx_strnew(len)))
        return (NULL);

    while (i < len) {
        substr[i] = s[start + i];
        i++;
    }

    return (substr);
}
