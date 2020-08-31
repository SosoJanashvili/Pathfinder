//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_inv_num_islands2(t_data *strct) {

    int size = strct->size;
    char **islands = strct->v_array;
    int i = 0;

    while (islands[i])
        i++;

    if (i != size) {
        mx_printerror("error: invalid number of islands\n");
        exit(1);
    }
}
