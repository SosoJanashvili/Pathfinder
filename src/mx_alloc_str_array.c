//
// Created by Soso Janashvili on 31.08.2020.
//

#include "../inc/pathfinder.h"

char **mx_alloc_str_array(int size) {
    char **arr = NULL;

    if (!(arr = (char **)malloc((size + 1) * sizeof(char *))))
        return NULL;

    for (int i = 0; i < size + 1; i++)
        arr[i] = NULL;

    return arr;
}
