#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {

    t_list *node = *list;

    if (node == NULL) {
        *list = mx_create_node(data);
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    node->next = mx_create_node(data);
}
