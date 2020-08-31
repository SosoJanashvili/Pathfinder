//
// Created by Soso Janashvili on 15.08.2020.
//

#include "../inc/pathfinder.h"

static int get_fd(char **argv);

int main(int argc, char **argv) {

    int fd;
    t_data strct;

    mx_error_usage(argc);
    fd = get_fd(argv);
    strct.size = mx_parse_first_line(fd, argv);

    strct.v_array = mx_alloc_str_array(strct.size);

    mx_parse_vertices(&strct, fd);

    floyd_warshall(&strct);

    mx_alloc_route(&strct);

    mx_print_output(&strct);

    mx_clean_up(&strct);
    close(fd);
    return 0;
}

static int get_fd(char **argv) {
    int fd;
    fd = open(argv[1], O_RDONLY);
    mx_error_file_exists(argv, fd);
    return fd;
}
