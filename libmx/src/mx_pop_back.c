#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {

    t_list *node = NULL;

    if (!head || !*head)
        return;

    if ((*head)->next == NULL) {
        free(head);
        return;
    }

    node = *head;

    while (node->next->next != NULL)
        node = node->next;

    free(node->next);
    node->next = NULL;
}
