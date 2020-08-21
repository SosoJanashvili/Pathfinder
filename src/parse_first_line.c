//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

int get_fd(char **argv) {
    int fd;
    fd = open(argv[1], O_RDONLY);
    check_if_file_exists(argv, fd);
    return fd;
}

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

    return v_quantity;
}

void prefill_matrix(int *graph, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i * size) / 4 == j) {
                *(graph + (i * size) + j) = 0;
            } else {
                *(graph + (i * size) + j) = INF;
            }
        }
    }
}

static bool contains_island(char **islands, char *island, int size) {
    for (int i = 0; i < size; i++) {
        if (mx_strcmp(islands[i], island) == 0)
            return true;
    }
    return false;
}

static int parse_line() {

    return 0;
}

void fill_matrix(int *graph, int size, char **islands, int fd) {

    char *island1 = NULL;
    char *island2 = NULL;
    int *distance = NULL;
    char *line = NULL;
    int sum_of_bridges = 0;

    for (int i = 0; i < size; i++) {

        mx_read_line(&line, 1, '\n', fd);
        check_line_for_errors(line);

    }

    int x;
}
