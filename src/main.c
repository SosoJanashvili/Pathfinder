//
// Created by Soso Janashvili on 15.08.2020.
//

#include "../inc/pathfinder.h"


char **create_str_array(int size) {
    char **arr = NULL;

    if (!(arr = (char **)malloc((size + 1) * sizeof(char *))))
        return NULL;

    for (int i = 0; i < size + 1; i++)
        arr[i] = NULL;

    return arr;
}

int main(int argc, char **argv) {

    int *graph = NULL;
    int size;
    int fd;
    char **islands = NULL;

    check_argc_quantity(argc);
    fd = get_fd(argv);
    size = parse_first_line(fd, argv);

    graph = (int *)malloc(size * size * sizeof(int));
    islands = create_str_array(size);

    fill_matrix(graph, size, islands, fd);

    //fill_graph(graph, size);
    print_graph(graph, size);
    mx_printstr("----------------------\n");
    floyd_warshall(graph, size, islands);

//    char c = '-';
//    mx_print_strarr(islands, &c);

    free(graph);
    mx_del_strarr(&islands);
    return 0;
}
