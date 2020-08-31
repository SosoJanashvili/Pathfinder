//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

void mx_clean_up(t_data *strct) {

    int n = strct->size;

    mx_del_strarr(&strct->v_array);

    for (int i = 0; i < n; i++) {
        free(strct->graph[i]);
    }
    free(strct->graph);

    for (int i = 0; i < n; i++) {
        free(strct->dist[i]);
    }
    free(strct->dist);

    for (int i = 0; i < n; i++) {
        free(strct->route[i]);
    }
    free(strct->route);
}
