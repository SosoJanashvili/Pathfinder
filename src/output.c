//
// Created by Soso Janashvili on 23.08.2020.
//

#include "../inc/pathfinder.h"

void print_list(t_list *head) {
    printf("HEAD->");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        printf("[%d]->", *(int *)(cur->data));
    }
    printf("NULL\n");
}

void delete_linked_list(t_list *head) {
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        printf("[%d]->", *(int *)(cur->data));
    }
}

void print_routes(int *dis, int *next) {

    t_list *head = mx_create_node(next);
    mx_push_back(&head, next + 1);
    mx_push_back(&head, next + 2);
    print_list(head);

}
