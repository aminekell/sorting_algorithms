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
            current->prev = NULL;
            current->next = sorted;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        } else {
            current->prev = temp;
            current->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = current;
            temp->next = current;
        }

        *list = sorted; 
        print_list(*list);
        current = next;
    }
}

