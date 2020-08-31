//
// Created by Soso Janashvili on 21.08.2020.
//

#include "../inc/pathfinder.h"

static void initialize(t_data *strct);

void floyd_warshall(t_data *strct) {

    int size = strct->size;

    mx_alloc_dist(strct);        // Allocate memory for dist matrix

    initialize(strct);

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (strct->dist[i][k] == INF || strct->dist[k][j] == INF)
                    continue;

                if (strct->dist[i][j] > strct->dist[i][k] + strct->dist[k][j]) {
                    strct->dist[i][j] = strct->dist[i][k] + strct->dist[k][j];
                }
            }
        }
    }
}

static void initialize(t_data *strct) {

    int size = strct->size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            strct->dist[i][j] = strct->graph[i][j];
        }
    }
}
