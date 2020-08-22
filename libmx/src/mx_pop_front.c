#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {

    t_list *temp = NULL;

    if (*head == NULL || head == NULL)
        return;

    temp = (*head)->next;
    free(*head);
    *head = temp;
}
