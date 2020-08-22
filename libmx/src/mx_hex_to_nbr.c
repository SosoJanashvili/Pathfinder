#include "../inc/libmx.h"

static unsigned long mx_get_num(char ch) {

    int i = 0;

    if ((int) ch >= 65 && (int) ch <= 90)
        ch = ch + 32;

    char hex_digits[16] = {'0', '1', '2', '3', '4', '5',
                          '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    unsigned long digits[16] =
            {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    while (ch != hex_digits[++i]);

    return digits[i];
}

unsigned long mx_hex_to_nbr(const char *hex) {

    unsigned long sum = 0U;
    int pos_num = 0;

    for (int i = mx_strlen(hex) - 1; i >= 0; i--) {
        sum = sum + (mx_get_num(hex[i]) * mx_pow(16, pos_num));
        pos_num++;
    }

    return sum;
}
