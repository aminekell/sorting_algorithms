#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Struct definition for the doubly linked list nodes */
typedef struct listint_s {
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
/* Other function prototypes... */

#endif /* SORT_H */

