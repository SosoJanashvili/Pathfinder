//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

void check_and_parse(int argc, char **argv) {

    int fd;
    int v_quantity;

    fd = open(argv[1], O_RDONLY);

    check_argc_quantity(argc);
    check_if_file_exists(argv, fd);

    v_quantity = parse_first_line(fd, argv);

}

int parse_first_line(int fd, char **argv) {

    char *s = NULL;
    int v_quantity;

    if (mx_read_line(&s, 10, '\n', fd) < 0)
        file_is_empty_error(argv);

    for (int i = 0; s[i]; i++)
        if (!mx_isdigit(s[i]))
            line_not_valid_error(1);

    v_quantity = mx_atoi(s);

    if (v_quantity < 1)
        line_not_valid_error(1);

    return v_quantity;
}
