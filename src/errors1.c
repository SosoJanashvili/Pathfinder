//
// Created by Soso Janashvili on 18.08.2020.
//

#include "../inc/pathfinder.h"

void check_argc_quantity(int argc) {
    if (argc != 2) {
        mx_printerror("usage: ./pathfinder [filename]\n");
        exit(101);
    }
}

void check_if_file_exists(char **argv, int fd) {
    if (fd < 0) {
        mx_printerror("error: file ");
        mx_printerror(argv[1]);
        mx_printerror(" does not exist\n");
        exit(101);
    }
}

void line_not_valid(int n) {
    mx_printerror("error: line ");
    mx_printerror(mx_itoa(n));
    mx_printerror(" is not valid\n");
    exit(101);
}

void file_is_empty_error(char **argv) {
    mx_printerror("error: file ");
    mx_printerror(argv[1]);
    mx_printerror(" is empty\n");
    exit(101);
}
