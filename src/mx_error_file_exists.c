//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_file_exists(char **argv, int fd) {
    if (fd < 0) {
        mx_printerror("error: file ");
        mx_printerror(argv[1]);
        mx_printerror(" does not exist\n");
        exit(1);
    }
}
