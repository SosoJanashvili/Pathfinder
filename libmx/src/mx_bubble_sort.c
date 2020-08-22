#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {

    int total_counter = 0;

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                mx_swap_arr_elements(&arr[j], &arr[j + 1]);
                total_counter++;
            }

    return total_counter;
}

//int main() {
//    char* arr[] = {"abc", "xyz", "ghi", "def"};
//
//    printf("Number of swaps: %d\n", mx_bubble_sort(arr, 4));
//}
