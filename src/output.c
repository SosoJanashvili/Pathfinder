//
// Created by Soso Janashvili on 23.08.2020.
//

#include "../inc/pathfinder.h"

void print_list(t_list *head) {
    mx_printstr("HEAD->");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        mx_printint(*(int *)(cur->data));
        mx_printstr("->");
    }
    mx_printstr("NULL\n");
}

static void print_path() {

}

static void print_route(t_list *head, char **islands) {
    mx_printstr("HEAD->");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        mx_printstr(islands[*(int *)(cur->data)]);
        mx_printstr("->");
    }
    mx_printstr("NULL\n");
}

static void print_distance() {

}

void delete_linked_list(t_list *head) {
    t_list *cur = NULL;
    while (head->next != NULL) {
        cur = head;
        head = head->next;
        free(cur);
    }
    free(head);
    head = NULL; //???
}

static t_list *construct_path(int *dis, int *next, int size, int a, int b) {
//    t_list *head = mx_create_node(next);
//    mx_push_back(&head, next + 1);
//    mx_push_back(&head, next + 2);

    // Storing the path in a vector
//    Vector<Integer> path = new Vector<Integer>();
//    path.add(u);
//
//    while (u != v)
//    {
//        u = Next[u][v];
//        path.add(u);
//    }
//    return path;

    int u = a;
    int v = b;

    t_list *head = mx_create_node(&u);

    while (u != v) {
        u = *(next + (u * size) + v);
        mx_push_back(&head, &u);
    }

    return head;
}

void print_routes(int *dis, int *next, int size, char **islands) {

    t_list *head = construct_path(dis, next, size, 0, 3);

    print_route(head, islands);

    delete_linked_list(head);

}
