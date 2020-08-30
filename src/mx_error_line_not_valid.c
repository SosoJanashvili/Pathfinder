//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_line_not_valid(int n) {
    mx_printerror("error: line ");
    mx_printerror(mx_itoa(n));
    mx_printerror(" is not valid\n");
    exit(1);
}
