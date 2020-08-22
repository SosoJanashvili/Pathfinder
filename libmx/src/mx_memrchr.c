#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {

    const unsigned char *p = s;
    unsigned char ch = c;
    int i = (int)n - 1;

    for (; i >= 0; i--) {
        if (p[i] == ch) {
            return (void *)&p[i];
        }
    }

    return NULL;
}



/*  code for main.c  */
//char str[30] = "xhis is a very long string";
//char ch = 'x';
//mx_printstr(mx_memrchr(str, ch, 20));
