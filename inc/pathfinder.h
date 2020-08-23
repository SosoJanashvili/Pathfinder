//
// Created by Soso Janashvili on 17.08.2020.
//

#ifndef PATHFINDER_PATHFINDER_H
#define PATHFINDER_PATHFINDER_H

#include <limits.h>

// Macros
#define INF 99
#define MX_MIN(x, y) ((x < y) ? x : y)

// To be removed later                                           !!!!!!!!!!!!!
#include "../libmx/inc/libmx.h"
void print_graph(int *graph, int size);
void fill_graph_with_ones(int *graph, int size);
void fill_graph(int *graph, int size);
// ----------------------------------


void check_for_errors(int fd, int argc, char **argv);

// Errors
void check_argc_quantity(int argc);
void check_if_file_exists(char **argv, int fd);
void line_not_valid_error(int n);
void file_is_empty_error(char **argv);
void check_line_for_errors(char *line);
void check_sum_of_bridges(int sum, int dis);
void error_duplicate_Bridges();
void error_inv_num_of_islands();
void error_inv_num_of_islands2(int size, char **islands);

// Parse
int get_fd(char **argv);
int parse_first_line(int fd, char **argv);
void prefill_matrix(int *graph, int size);
void fill_matrix(int *graph, int size, char **islands, int fd);

void floyd_warshall(int *graph, int size);


// Printing data
void print_routes(int *dis, int *next);
void print_list(t_list* head);

#endif //PATHFINDER_PATHFINDER_H
