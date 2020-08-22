#include "../inc/libmx.h"

static int append_line(char **lineptr, char delim, const int fd, char **s) {
    int len = 0;
    char *temp = NULL;

    while (s[fd][len] != delim && s[fd][len] != '\0')
        len++;

    if (s[fd][len] == '\n') {
        *lineptr = mx_strsub(s[fd], 0, len);
        temp = mx_strdup(&s[fd][len + 1]);
        mx_strdel(&s[fd]);
        s[fd] = temp;
        if (s[fd][0] == '\0')
            mx_strdel(&s[fd]);
    } else {
        *lineptr = strdup(s[fd]);
        mx_strdel(&s[fd]);
    }
    return len;
}

static int output(char **lineptr, int ret_v, char delim, const int fd, char **s) {

    if (ret_v == -1 && s[fd] == NULL)            // Checks if fd is valid;
        return -2;

    if (s[fd] == NULL)           // If there's nothing to write to lineptr
        return -1;

    return append_line(lineptr, delim, fd, s);
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    int ret_v;
    static char *s[5555];
    char *buff = mx_strnew(buf_size);
    char *temp = NULL;

    if (lineptr == NULL || buf_size < 1)
        return -2;

    while ((ret_v = read(fd, buff, buf_size)) > 0) {
        if (s[fd] == NULL) {
            s[fd] = mx_strdup(buff);
        } else {
            temp = mx_strjoin(s[fd], buff);
            free(s[fd]);
            s[fd] = temp;
        }
        if (mx_strchr(s[fd], delim) != NULL)
            break;
    }
    free(buff);
    return output(lineptr, ret_v, delim, fd, s);
}
