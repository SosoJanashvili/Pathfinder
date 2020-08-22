//
// Created by sjana on 22.08.2020.
//

#include "../inc/libmx.h"

bool mx_isalpha(int c) {
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}
