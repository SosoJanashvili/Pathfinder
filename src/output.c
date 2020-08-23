//
// Created by Soso Janashvili on 23.08.2020.
//

#include "../inc/pathfinder.h"

t_lst *mx_createnode(int n) {

    t_lst *lst = malloc(sizeof(t_lst));

    if (!lst) return NULL;

    lst->n = n;
    lst->next = NULL;

    return lst;
}

void mx_pushback(t_lst **list, int n) {

    t_lst *node = *list;

    if (node == NULL) {
        *list = mx_createnode(n);
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    node->next = mx_createnode(n);
}

void print_list(t_list *head) {
    mx_printstr("HEAD->");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        mx_printint(*(int *)(cur->data));
        mx_printstr("->");
    }
    mx_printstr("NULL\n");
}

static void print_path(char **islands, int i, int j) {
    mx_printstr("Path: ");
    mx_printstr(islands[i]);
    mx_printstr(" -> ");
    mx_printstr(islands[j]);
    mx_printstr("\n");
}

static void print_route(t_lst *head, char **islands) {
    mx_printstr("Route: ");
    for (t_lst *cur = head; cur != NULL; cur = cur->next) {
        mx_printstr(islands[(cur->n)]);
        if (cur->next)
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
}

static void print_distance(t_lst *path, int *dis, int size) {

    int distance;
    int total = 0;

    mx_printstr("Distance: ");

    if (path->next->next == NULL) {
        mx_printint(*(dis + (path->n * size) + path->next->n));
    } else {

        for (t_lst *cur = path; cur->next != NULL; cur = cur->next) {
            distance = *(dis + (cur->n * size) + cur->next->n);
            mx_printint(distance);
            total += distance;
            if (cur->next->next)
                mx_printstr(" + ");
        }

    }
    if (path->next->next != NULL) {
        mx_printstr(" = ");
        mx_printint(total);
    }
    mx_printstr("\n");
}

void delete_linked_list(t_lst *head) {
    t_lst *cur = NULL;
    while (head->next != NULL) {
        cur = head;
        head = head->next;
        free(cur);
    }
    free(head);
    head = NULL;
}

static t_lst *construct_path(int *dis, int *next, int size, int a, int b) {

    int u = a;
    int v = b;

    t_lst *head = mx_createnode(u);

    while (u != v) {
        u = *(next + (u * size) + v);
        mx_pushback(&head, u);
    }

    return head;
}

void print_routes(int *dis, int *next, int size, char **islands) {

    t_lst *path = NULL;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i != j) {
                path = construct_path(dis, next, size, i, j);
                mx_printstr("========================================\n");
                print_path(islands, i, j);
                print_route(path, islands);
                print_distance(path, dis, size);
                mx_printstr("========================================\n");
                delete_linked_list(path);
            }
        }
    }

}
