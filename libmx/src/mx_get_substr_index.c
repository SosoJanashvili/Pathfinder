#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {

    if (!str || !sub)
        return -2;

    int len = mx_strlen(sub);

    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_strncmp( str + i, sub, len) == 0) {
            return i;
        }
    }

    return -1;
}
