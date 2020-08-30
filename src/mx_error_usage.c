//
// Created by Soso Janashvili on 30.08.2020.
//

#include "../inc/pathfinder.h"

void mx_error_usage(int argc) {
    if (argc != 2) {
        mx_printerror("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
