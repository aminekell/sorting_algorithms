#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list) {
	 listint_t *sorted = NULL, *current = *list;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;


    while (current != NULL) {
        listint_t *next = current->next;

        listint_t *temp_sorted = sorted;
        listint_t *temp = NULL;

        while (temp_sorted != NULL && temp_sorted->n < current->n) {
            temp = temp_sorted;
            temp_sorted = temp_sorted->next;
        }

        if (temp == NULL) {
            current->next = sorted;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        } else {
            temp->next = current;
            current->prev = temp;
            current->next = temp_sorted;
            if (temp_sorted != NULL)
                temp_sorted->prev = current;
        }

        current = next;
    }

    *list = sorted;
}

