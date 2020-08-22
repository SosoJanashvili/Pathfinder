#include "../inc/libmx.h"

static char *mx_copy(char const *s, char c) {

    char *word = NULL;
    int	i = 0;

    while (s[i] && s[i] != c)
        i++;

    if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);

    i = 0;
    while (s[i] && s[i] != c) {
        word[i] = s[i];
        i++;
    }

    word[i] = '\0';
    return word;
}

char **mx_strsplit(char const *s, char c) {
    char **strarr = NULL;
    int word = 0;
    int i = 0;

    if (!s)
        return (NULL);

    if (!(strarr = (char **)
            malloc(sizeof(char *) * (mx_count_words(s, c) + 1))))
        return (NULL);

    while (s[i]) {
        if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c)) {
            strarr[word++] = mx_copy(s + i, c);
        }
        i++;
    }
    strarr[word] = NULL;
    return strarr;
}
