//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

void mx_clean_up(t_data *strct) {
    mx_del_strarr(&strct->v_array);
    free(strct->graph);
    free(strct->dist);
    free(strct->route);
}
