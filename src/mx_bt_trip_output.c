#include "../inc/pathfinder.h"

static void print_distance(t_data *stct, t_backtrack *stack);

void mx_ret_trip_output(t_data *stct, t_backtrack *stack) {
    int i = stack->path[1];
    int j = stack->path[0];
    int n = stack->size;

    mx_printstr("========================================");
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(stct->v_array[i]);
    mx_printstr(" -> ");
    mx_printstr(stct->v_array[j]);
    mx_printstr("\nRoute: ");
    for (int k = 1; k <= n; k++) {
        mx_printstr(stct->v_array[stack->path[k]]);
        (k < n) ? mx_printstr(" -> ") : mx_printstr("");
    }
    print_distance(stct, stack);
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

static void print_distance(t_data *stct, t_backtrack *stack) {
    int sum = 0;
    int n = stack->size;

    mx_printstr("\nDistance: ");
    if (n == 2)
        mx_printint(stct->dist[stack->path[n]][stack->path[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_printint(stct->dist[stack->path[i]][stack->path[i + 1]]);
            sum += stct->dist[stack->path[i]][stack->path[i + 1]];
            (i + 1 < n) ? mx_printstr(" + ") : mx_printstr("");
        }
        mx_printstr(" = ");
        mx_printint(sum);
    }
}
