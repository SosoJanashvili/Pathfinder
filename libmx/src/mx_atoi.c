#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int result = 0;

    while (mx_isspace(str[i]) || str[i] == '-' || str[i] == '+') {
        if ((str[i] == '-' && !mx_isdigit(str[i + 1])) ||
             (str[i] == '+' && !mx_isdigit(str[i + 1]))) {
            return 0;
        }
        i++;
    }
    for (int j = i; mx_isdigit(str[j]); j++) {
        result = (result * 10) + (str[j] - 48);
    }

    if (i > 1 && str[i - 1] == '-') {
        return -result;
    }
    return result;
}
