#include "../inc/libmx.h"

static int get_str_length(const char *file) {

    int strlen = 0;
    char buf;
    int fl = open(file, O_RDONLY);

    while (read(fl, &buf, 1) > 0)
        strlen++;

    close(fl);
    return strlen;
}

char *mx_file_to_str(const char *file) {
    char *str = NULL;
    int strlen;
    int fl = 0;

    if (!file)
        return NULL;

    fl = open(file, O_RDONLY);
    if (fl == -1) {
        return NULL;
    }
    strlen = get_str_length(file);
    if (!(str = mx_strnew(strlen)))
        return NULL;
    if (read(fl, str, strlen) == -1)
        return NULL;

    close(fl);
    return str;
}
