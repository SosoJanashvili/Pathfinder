//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

int parse_first_line(int fd, char **argv) {

    char *s = NULL;
    int v_quantity;

    if (mx_read_line(&s, 1, '\n', fd) < 0)
        file_is_empty_error(argv);

    for (int i = 0; s[i]; i++)
        if (!mx_isdigit(s[i]))
            line_not_valid_error(1);

    v_quantity = mx_atoi(s);

    if (v_quantity < 1)
        line_not_valid_error(1);

    free(s);
    return v_quantity;
}
