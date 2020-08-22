#include "../inc/libmx.h"

static int num_len(unsigned long num) {
    int length = 0;

    while (num) {
        num /= 16;
        length++;
    }
    return length;
}

char *mx_nbr_to_hex(unsigned long nbr) {

    char *hex = NULL;
    int len = num_len(nbr);
    int temp;

    if (!(hex = malloc(len)))
        return NULL;

    if (nbr == 0)
        return mx_strcpy(hex, "0");

    while (nbr) {
        temp = nbr % 16;
        if (temp < 10)
            hex[--len] = 48 + temp;
        if (temp >= 10)
            hex[--len] = 87 + temp;
        nbr /= 16;
    }
    return hex;
}
