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

    free(s);
    return v_quantity;
}

void prefill_matrix(int *graph, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i * size) / size == j) {
                *(graph + (i * size) + j) = 0;
            } else {
                *(graph + (i * size) + j) = INF;
            }
        }
    }
}

void insert_to_array(char **islands, char *island, int size) {
    int i = 0;
    int len = 0;

    while (islands[i]) {
        if (mx_strcmp(islands[i], island) == 0) {
            free(island);
            return;
        }
        i++;
    }

    while (islands[len])
        len++;

    if (len == size) {
        error_inv_num_of_islands();
    }
    islands[i] = island;
}

static void send_num_to_matrix(char **islands, char*isl1, char *isl2, int *distance, int *graph, int size) {

    int i = 0;
    int j = 0;

    while (strcmp(islands[i], isl1) != 0 && islands[i])
        i++;

    while (strcmp(islands[j], isl2) != 0 && islands[j])
        j++;

    if (*(graph + (i * size) + j) == INF) {
        *(graph + (i * size) + j) = *distance;
    } else {
        error_duplicate_Bridges();
    }

    if (*(graph + (j * size) + i) == INF) {
        *(graph + (j * size) + i) = *distance;
    } else {
        error_duplicate_Bridges();
    }
}

static char *get_island_1(char *line, int line_num) {
    int i = 0;
    char *str = NULL;

    for (; line[i] != '-'; i++)
        if (!mx_isalpha(line[i]))
            line_not_valid_error(line_num);

    str = mx_strsub(line, 0, i);

    return str;
}

static char *get_island_2(char *line, int line_num) {
    int i = 0;
    int j = 0;

    for (; line[i] != '-'; i++)
        if (!mx_isalpha(line[i]))
            line_not_valid_error(line_num);

    j = i + 1;
    for (i = i + 1; line[i] != ','; i++)
        if (!mx_isalpha(line[i]))
            line_not_valid_error(line_num);

    return mx_strsub(line, j, i - j);
}

static int get_distance(char *line, int line_num) {

    char *temp = NULL;
    int result = 0;
    int i = 0;
    int j = 0;

    for (; line[i] != ','; i++)
        if (!mx_isalpha(line[i]) && line[i] != '-')
            line_not_valid_error(line_num);

    j = i + 1;
    while (line[j] != '\0') {
        if (!mx_isdigit(line[j]))
            line_not_valid_error(line_num);
        j++;
    }

    temp = mx_strsub(line, i + 1, j - i);
    result = mx_atoi(temp);
    free(temp);
    return result;
}

void fill_matrix(int *graph, int size, char **islands, int fd) {

    int distance;
    char *island1 = NULL;
    char *island2 = NULL;
    char *line = NULL;
    int sum_of_bridges = 0;

    prefill_matrix(graph, size);

    for (int i = 0; mx_read_line(&line, 1, '\n', fd) > 0; i++) {

        island1 = get_island_1(line, i + 2);
        island2 = get_island_2(line, i + 2);

        insert_to_array(islands, mx_strdup(island1), size);
        insert_to_array(islands, mx_strdup(island2), size);

        distance = get_distance(line, i + 2);   //get distance between bridges

        send_num_to_matrix(islands,island1,island2, &distance, graph, size);

        check_sum_of_bridges(sum_of_bridges, distance);
        sum_of_bridges += distance;

        free(island1);
        free(island2);
        free(line);
    }

    error_inv_num_of_islands2(size, islands);
}
