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

int check_if_file_exists(char **argv) {

    int fd;

    fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        mx_printerror("error: file ");
        mx_printerror(argv[1]);
        mx_printerror(" does not exist\n");
    }

    return fd;
}

