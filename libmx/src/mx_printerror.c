//
// Created by Soso Janashvili on 18.08.2020.
//

#include "../inc/libmx.h"

void mx_printerror(const char *s) {
    if (!s) {
        return;
    }
    write(2, s, mx_strlen(s));
}
