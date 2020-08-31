//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

void mx_print_output(t_data *strct) {
    for (int i = 0; i < strct->size; i++) {
        for (int j = 0; j < strct->size; j++) {
            if (i < j)
                mx_find_all_paths(strct, i, j);
        }
    }
}
