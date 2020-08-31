#include "../inc/pathfinder.h"

static int get_stack_index(t_backtrack *stack);
static void push_to_stack(t_backtrack *path_stack, int elem);
static int pop_from_stack(t_backtrack *stack);
static bool check_next_v(t_data *stct, t_backtrack *stack, int next_v);

void mx_back_path(t_data *stct, t_backtrack *stack) {
    int a = stack->c;

    if (get_stack_index(stack) == stack->path[0]) {
        mx_ret_trip_output(stct, stack);
        return;
    }
    else {
        for (int i = 0; i < a; i++) {
            if (check_next_v(stct, stack, i)) {
                push_to_stack(stack, i);
                mx_back_path(stct, stack);
                pop_from_stack(stack);
            }
        }
    }
}

static int get_stack_index(t_backtrack *stack) {
    return stack->path[stack->size];
}

static void push_to_stack(t_backtrack *stack, int elem) {
    if (stack->size < stack->c) {
        stack->size++;
        stack->path[stack->size] = elem;
    }
}

static int pop_from_stack(t_backtrack *stack) {
    if (stack->size > 1) {
        stack->size--;
        return stack->path[stack->size + 1];
    }
    return stack->path[1];
}

static bool check_next_v(t_data *stct, t_backtrack *stack, int next_v) {
    int k = get_stack_index(stack);
    int j = stack->path[0];

    if (k != next_v) {
        if (stct->route[k][next_v] == stct->dist[j][k]
            - stct->dist[j][next_v])
            return true;
    }
    return false;
}
