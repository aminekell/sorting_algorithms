#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list) {
	listint_t *current = (*list)->next;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    

    while (current != NULL) {
        listint_t *temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n) {
            int temp_val = temp->n;
            temp->n = temp->prev->n;
            temp->prev->n = temp_val;

            temp = temp->prev;
            print_list(*list);
        }

        current = current->next;
    }
}

