//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_alloc_graph(t_data *strct) {

    int size = strct->size;

    strct->graph = NULL;

    strct->graph = (int **)malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {

        strct->graph[i] = (int *)malloc(sizeof(int) * size);

        for (int j = 0; j < size; j++) {
            strct->graph[i][j] = 0;
        }
    }

}
