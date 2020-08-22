#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

    const unsigned char *haystack = NULL;
    const unsigned char *needle = NULL;

    if (!big || !little || big_len == 0 || little_len == 0 || big_len < little_len)
        return NULL;

    haystack = (unsigned char *)big;
    needle = (unsigned char *)little;

    while (*haystack) {

        if (mx_memcmp(haystack, needle, little_len) == 0)
            return (void *)haystack;

        haystack++;
    }

    return NULL;
}

/*  code for main.c  */
//char str[30] = "this is a very long string";
//char str2[3] = "ing";
//mx_printstr( mx_memmem(str, 30, str2, 3) );
