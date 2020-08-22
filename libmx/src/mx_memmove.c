#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {

    void *temp = NULL;

    if (!dst && !src)
        return NULL;

    if(!(temp = malloc(len)))
        return NULL;

    mx_memcpy(temp, src, len);

    mx_memcpy(dst, temp, len);

    free(temp);

    return dst;
}


/*  Code for main.c  */
//char str[] = "Hello World";
//char str2[] = "JELLO worlD";
//mx_memmove(str, str2, 11);
//mx_printstr( str );
