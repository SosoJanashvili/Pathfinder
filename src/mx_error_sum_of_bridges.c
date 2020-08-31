//
// Created by Soso Janashvili on 18.08.2020.
//

#include "../inc/pathfinder.h"


void check_sum_of_bridges(int sum, int dis) {
    if (((long long)sum + (long long)dis) > INT_MAX) {
        mx_printerror("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}
