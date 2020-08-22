#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {

    if (*arr && delim){

        while (*arr) {
            mx_printstr(*arr);

            if (*(arr + 1))
                mx_printstr(delim);

            arr++;
        }

        mx_printstr("\n");
    }
}


/* Code for main.c */
//char *arr[] = {"Hello", "###", "There", "??", "!", "0", NULL, NULL, NULL, NULL};
//char delim =  '_';
//mx_print_strarr(arr, &delim);



/*  Old...  */
/*
void mx_print_strarr(char **arr, const char *delim) {

    int i = 0;
    char ch;
    int count = 0;

    if(!(*arr) || !delim)
        return;

    ch = *delim;
    while (*(arr+count)) {
        count++;
    }

    while (i < count - 1) {
        mx_printstr(arr[i]);
        mx_printstr(&ch);
        i++;
    }
    mx_printstr(arr[i]);
    mx_printchar('\n');
}
*/
