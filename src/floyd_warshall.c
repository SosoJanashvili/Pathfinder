//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

static void initialize(int *graph, int *dis, int *next, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(dis + (i * size) + j) = *(graph + (i * size) + j);

            if (*(graph + (i * size) + j) == INF) {
                *(next + (i * size) + j) = -1;
            } else {
                *(next + (i * size) + j) = j;
            }
        }
    }
}

void floyd_warshall(int *graph, int size) {

    int *dis = (int *)malloc(size * size * sizeof(int));
    int *next = (int *)malloc(size * size * sizeof(int));

    initialize(graph, dis, next, size);

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (*(dis + (i * size) + k) == INF || *(dis + (k * size) + j) == INF)
                    continue;

                if (*(dis + (i * size) + j) > *(dis + (i * size) + k) + *(dis + (k * size) + j)) {
                    *(dis + (i * size) + j) = *(dis + (i * size) + k) + *(dis + (k * size) + j);
                    *(next + (i * size) + j) = *(next + (i * size) + k);
                }
            }
        }
    }
    print_graph(dis, size);
    mx_printstr("----------------------\n");
    print_graph(next, size);
    mx_printstr("----------------------\n");

    print_routes(dis, next, size);

    if (dis)
        free(dis);
    if (next)
        free(next);
}
