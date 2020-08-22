//
// Created by sjana on 21.08.2020.
//

#include "../inc/pathfinder.h"

void print_graph(int *graph, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mx_printint(*(graph + i * size + j));
            mx_printstr("   ");
        }
        printf("\n");
    }

}

void fill_graph_with_ones(int *graph, int size) {

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            *(graph + i * size + j) = 1;
            *(graph + (2 * size) + 0 ) = 77;
        }
}

void fill_graph(int *graph, int size) {

    *(graph + 0)  = 0;
    *(graph + 1)  = 8;
    *(graph + 2)  = 10;
    *(graph + 3)  = INF;

    *(graph + (1 * size) + 0) = 8;
    *(graph + (1 * size) + 1) = 0;
    *(graph + (1 * size) + 2) = 3;
    *(graph + (1 * size) + 3) = INF;

    *(graph + (2 * size) + 0) = 10;
    *(graph + (2 * size) + 1) = 3;
    *(graph + (2 * size) + 2) = 0;
    *(graph + (2 * size) + 3) = 5;

    *(graph + (3 * size) + 0) = INF;
    *(graph + (3 * size) + 1) = INF;
    *(graph + (3 * size) + 2) = 5;
    *(graph + (3 * size) + 3) = 0;
}
