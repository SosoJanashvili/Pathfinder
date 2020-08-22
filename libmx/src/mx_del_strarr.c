#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {

    if (!arr || !(*arr)) return;

    char **pstr = NULL;

    pstr = *arr;
    while (*pstr != NULL) {
        mx_strdel(pstr);
        pstr++;
    }

    free(*arr);
    *arr = NULL;
}

//int main() {
//
//    char **str;
//    int i = 0;
//
//    str = malloc(100);
//
//    for (; i < 9; i++) {
//        str[i] = mx_strnew(10);
//        str[i] = strdup("string");
//    }
//
//    str[i] = NULL;
//
//    mx_del_strarr(&str);
//
//    return 0;
//}
