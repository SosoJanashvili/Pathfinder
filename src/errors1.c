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

void line_not_valid_error(int n) {
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

void error_duplicate_Bridges() {
    mx_printerror("error: duplicate bridges\n");
    exit(101);
}

void error_inv_num_of_islands() {
    mx_printerror("error: invalid number of islands\n");
    exit(101);
}

void error_inv_num_of_islands2(int size, char **islands) {

    int i = 0;

    while (islands[i])
        i++;

    if (i != size) {
        mx_printerror("error: invalid number of islands\n");
        exit(101);
    }
}

void check_sum_of_bridges(int sum, int dis) {
    if (((long long)sum + (long long)dis) > INT_MAX) {
        mx_printerror("error: sum of bridges lengths is too big\n");
        exit(101);
    }
}
