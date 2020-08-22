#include "../inc/libmx.h"

static void mx_write_digits(int n) {
    char temp[10];
    int i = 0;

    for (; n > 0; i++) {
        temp[i] = (char)((n % 10) + 48);
        n = n / 10;
    }

    for (; i > 0; i--) {
        mx_printchar(temp[i - 1]);
    }
}

void mx_printint(int n) {

    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    } else if (n == 0) {
        write(1, "0", 1);
        return;
    }

    if (n < 0) {
        n = -n;
        mx_printchar('-');
    }

    mx_write_digits(n);
}
