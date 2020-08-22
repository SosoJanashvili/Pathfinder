#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {

    int start = 0;
    int mid;
    int end = size - 1;

    if (!*arr)
        return -1;

    while (start <= end) {
        (*count)++;
        mid = (start + end) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        else if (mx_strcmp(arr[mid], s) > 0)
            end = mid - 1;
        else
            start = mid + 1;
    }
    *count = 0;
    return -1;
}

//int main() {
//    char* arr[] = {"222", "Abcd", "aBc", "ab", "az", "z"};
//    int count = 0;
//
//    int x = mx_binary_search(arr, 6, "ab", &count);
//    printf("position of string in array: %d\n", x);
//    printf("Number of iterations: %d\n", count);
//}
