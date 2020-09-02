//
// Created by Soso Janashvili on 29.08.2020.
//

#include "../inc/pathfinder.h"

static void create_matrix(t_data *strct);
static char *get_island_1(char *line, int line_num);
static char *get_island_2(char *line, int line_num);
static int get_distance(char *line, int line_num);
static void insert_to_array(t_data *strct, char *island);
static void send_num_to_matrix(t_data *strct, char*isl1, char *isl2, int *distance);

void mx_parse_vertices(t_data *strct, int fd) {

    int distance;
    char *island1 = NULL;
    char *island2 = NULL;
    char *line = NULL;
    int sum_of_bridges = 0;

    create_matrix(strct);

    for (int i = 0; mx_read_line(&line, 1, '\n', fd) > 0; i++) {

        island1 = get_island_1(line, i + 2);
        island2 = get_island_2(line, i + 2);

        insert_to_array(strct, mx_strdup(island1));
        insert_to_array(strct, mx_strdup(island2));

        distance = get_distance(line, i + 2);   //get distance between bridges

        send_num_to_matrix(strct, island1, island2, &distance);

        mx_error_sum_of_bridges(sum_of_bridges, distance);
        sum_of_bridges += distance;

        free(island1);
        free(island2);
        free(line);
    }

    mx_error_inv_num_islands2(strct);
}

static void send_num_to_matrix(t_data *strct, char*isl1, char *isl2, int *distance) {

    char **islands = strct->v_array;
    int i = 0;
    int j = 0;

    while (mx_strcmp(islands[i], isl1) != 0 && islands[i])
        i++;

    while (mx_strcmp(islands[j], isl2) != 0 && islands[j])
        j++;

    if (strct->graph[i][j] == INF) {
        strct->graph[i][j] = *distance;
    } else {
        mx_error_duplicate();
    }

    if (strct->graph[j][i] == INF) {
        strct->graph[j][i] = *distance;
    } else {
        mx_error_duplicate();
    }
}

static void create_matrix(t_data *strct) {

    int size = strct->size;

    mx_alloc_graph(strct);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i * size) / size == j) {
                strct->graph[i][j] = 0;
            }
            else {
                strct->graph[i][j] = INF;
            }
        }
    }
}

static char *get_island_1(char *line, int line_num) {
    int i = 0;
    char *str = NULL;

    for (; line[i] != '-'; i++)
        if (!mx_isalpha(line[i]))
            mx_error_line_not_valid(line_num);

    str = mx_strsub(line, 0, i);

    return str;
}

static char *get_island_2(char *line, int line_num) {
    int i = 0;
    int j = 0;

    for (; line[i] != '-'; i++)
        if (!mx_isalpha(line[i]))
            mx_error_line_not_valid(line_num);

    j = i + 1;
    for (i = i + 1; line[i] != ','; i++)
        if (!mx_isalpha(line[i]))
            mx_error_line_not_valid(line_num);

    return mx_strsub(line, j, i - j);
}

static int get_distance(char *line, int line_num) {

    char *temp = NULL;
    int result = 0;
    int i = 0;
    int j = 0;

    for (; line[i] != ','; i++)
        if (!mx_isalpha(line[i]) && line[i] != '-')
            mx_error_line_not_valid(line_num);

    j = i + 1;
    while (line[j] != '\0') {
        if (!mx_isdigit(line[j]))
            mx_error_line_not_valid(line_num);
        j++;
    }

    temp = mx_strsub(line, i + 1, j - i);
    result = mx_atoi(temp);
    free(temp);
    return result;
}

static void insert_to_array(t_data *strct, char *island) {
    int i = 0;
    int len = 0;
    int size = strct->size;
    char **islands = strct->v_array;

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
        mx_error_inv_num_islands();
    }
    islands[i] = island;
}
