//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_line_not_valid(int n) {

    char *str = mx_itoa(n);

    mx_printerror("error: line ");
    mx_printerror(str);
    mx_printerror(" is not valid\n");

    free(str);

    exit(1);
}
