//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

void mx_alloc_route(t_data *strct) {

    int size = strct->size;

    strct->route = NULL;

    strct->route = (int **)malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {

        strct->route[i] = (int *)malloc(sizeof(int) * size);

        for (int j = 0; j < size; j++) {
            strct->route[i][j] = strct->graph[i][j];
        }
    }

}
