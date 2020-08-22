#include "../inc/libmx.h"

static void mx_to_string(int number, char *str) {

    int i = 0;
    bool is_negative = false;

    if (number == 0)
        str[i] = '0';

    if (number < 0) {
        number = -number;
        is_negative = true;
    }

    for (; number > 0; i++) {
        str[i] = (char)((number % 10) + 48);
        number = number / 10;
    }

    if (is_negative)
        str[i] = '-';
}

char *mx_itoa(int number) {

    char *str = NULL;

    if (number == -2147483648) {
        str = mx_strdup("-2147483648");
        return str;
    }

    if (!(str = mx_strnew(12)))
        return NULL;

    mx_to_string(number, str);

    mx_str_reverse(str);
    return str;
}
