//
// Created by Soso Janashvili on 17.08.2020.
//

#ifndef PATHFINDER_PATHFINDER_H
#define PATHFINDER_PATHFINDER_H

typedef struct s_data {
    char **v_array;             // String array for vertices
    int size;                   // Quantity of vertices
    int **graph;                // Initial matrix
    int **dist;
    int **route;
}           t_data;

typedef struct s_backtrack {
    int size;
    int *path;
    int c;
}           t_backtrack;

#include <limits.h>

// Macros
#define INF INT_MAX

// To be removed later                                           !!!!!!!!!!!!!
#include "../libmx/inc/libmx.h"

// Errors
void mx_error_usage(int argc);
void mx_error_file_exists(char **argv, int fd);
void mx_error_line_not_valid(int n);
void mx_error_file_is_empty(char **argv);
void mx_error_sum_of_bridges(int sum, int dis);
void mx_error_duplicate();
void mx_error_inv_num_islands();
void mx_error_inv_num_islands2(t_data *strct);

// Memory
void mx_alloc_dist(t_data *strct);
void mx_alloc_route(t_data *strct);
void mx_alloc_graph(t_data *strct);
char **mx_alloc_str_array(int size);
void mx_clean_up(t_data *strct);

// Parsing files
int mx_parse_first_line(int fd, char **argv);
void mx_parse_vertices(t_data *strct, int fd);

// Floyd_Warshall
void floyd_warshall(t_data *strct);

// Printing data
void mx_print_output(t_data *strct);

// Backtracking
void mx_find_all_paths(t_data *strct, int st, int end);
void mx_back_path(t_data *strct, t_backtrack *stack);
void mx_ret_trip_output(t_data *strct, t_backtrack *stack);

#endif //PATHFINDER_PATHFINDER_H
