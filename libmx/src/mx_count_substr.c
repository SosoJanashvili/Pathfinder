#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {

    if (!str || !sub)
        return -1;

    int len = mx_strlen(sub);
    int count = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_strncmp(str + i, sub, len) == 0) {
            count++;
        }
    }

    return count;
}
