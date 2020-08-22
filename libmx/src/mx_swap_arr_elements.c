#include "../inc/libmx.h"

void mx_swap_arr_elements(char **s1, char **s2) {
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
