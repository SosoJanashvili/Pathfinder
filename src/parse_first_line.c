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

static void parse_line(char *line, char *isl1, char *isl2, int *dis, int line_num) {

    int i = 0;
    int j = 0;
    char *temp = NULL;

    for (; line[i] != '-'; i++)
        if (!mx_isalpha(line[i]))
            line_not_valid_error(line_num);

    isl1 = mx_strsub(line, 0, i);

    j = i + 1;
    for (i = i + 1; line[i] != ','; i++)
        if (!mx_isalpha(line[i]))
            line_not_valid_error(line_num);

    isl2 = mx_strsub(line, j, i - j);

    j = i + 1;
    for (i = i + 1; line[i] != '\0'; i++)
        if (!mx_isdigit(line[i]))
            line_not_valid_error(line_num);

    temp = mx_strsub(line, j, i - j);
    *dis = mx_atoi(temp);
    free(temp);
}

void fill_matrix(int *graph, int size, char **islands, int fd) {

    char *island1 = NULL;
    char *island2 = NULL;
    int distance;
    char *line = NULL;
    int sum_of_bridges = 0;

    for (int i = 0; i < size; i++) {

        mx_read_line(&line, 1, '\n', fd);
        check_line_for_errors(line);                                  // note
        parse_line(line, island1, island2, &distance, i + 2);

        check_sum_of_bridges(sum_of_bridges, distance);
        sum_of_bridges += distance;
    }

}
