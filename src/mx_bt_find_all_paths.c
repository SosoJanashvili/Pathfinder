#include "../inc/pathfinder.h"

static void init_stack(t_data *stct, t_backtrack **path_stack, int i, int j);

void mx_find_all_paths(t_data *stct, int st, int end) {
    t_backtrack *stack = NULL;

    init_stack(stct, &stack, st, end);
    mx_back_path(stct, stack);
    free(stack->path);
    free(stack);
}

static void init_stack(t_data *stct, t_backtrack **stack, int i, int j) {
    *stack = malloc(sizeof(t_backtrack));
    int n = stct->size;

    if ((*stack) == NULL)
        exit(1);
    (*stack)->path = malloc(sizeof(int) * n + 1);
    (*stack)->size = 1;
    (*stack)->path[1] = i;
    (*stack)->path[0] = j;
    (*stack)->c = n;
}
