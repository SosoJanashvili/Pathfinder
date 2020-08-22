#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {

    char arr[4];
    unsigned int len;

    if (c < 128) {
        arr[0] = ((c >> 0) & 127) | 0;
        len = 1;
    } else if (c < 2048) {
        arr[0] = ((c >> 6) & 31) | 192;
        arr[1] = ((c >> 0) & 63) | 128;
        len = 2;
    } else if (c < 65536) {
        arr[0] = ((c >> 12) & 15) | 224;
        arr[1] = ((c >> 6) & 63) | 128;
        arr[2] = ((c >> 0) & 63) | 128;
        len = 3;
    } else {
        arr[0] = ((c >> 18) & 7) | 240;
        arr[1] = ((c >> 12) & 63) | 128;
        arr[2] = ((c >> 6) & 63) | 128;
        arr[3] = ((c >> 0) & 63) | 128;
        len = 4;
    }

    write(1, arr, len);
}

//   Code for main.c
//    for (int i = 50; i < 100000; i+=10){
//        mx_print_unicode(i);
//    }
//    for (int i = 4304; i < 4337; i++){
//        mx_print_unicode(i);
//    }

