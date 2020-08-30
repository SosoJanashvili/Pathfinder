//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

int parse_first_line(int fd, char **argv) {

    char *s = NULL;
    int v_quantity;

    if (mx_read_line(&s, 1, '\n', fd) < 0)
        mx_error_file_is_empty(argv);

    for (int i = 0; s[i]; i++)
        if (!mx_isdigit(s[i]))
            mx_error_line_not_valid(1);

    v_quantity = mx_atoi(s);

    if (v_quantity < 1)
        mx_error_line_not_valid(1);

    free(s);
    return v_quantity;
}
