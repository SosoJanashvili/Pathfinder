//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_file_is_empty(char **argv) {
    mx_printerror("error: file ");
    mx_printerror(argv[1]);
    mx_printerror(" is empty\n");
    exit(1);
}
