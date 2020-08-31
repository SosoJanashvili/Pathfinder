//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

void mx_alloc_dist(t_data *strct) {

    int size = strct->size;

    strct->dist = NULL;

    strct->dist = (int **)malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {

        strct->dist[i] = (int *)malloc(sizeof(int) * size);

        for (int j = 0; j < size; j++) {
            strct->dist[i][j] = 0;
        }
    }

}
