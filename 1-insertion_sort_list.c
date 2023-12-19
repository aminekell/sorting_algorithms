#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order using Selection sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size) {
    size_t i, j;

    for (i = 0; i < size - 1; i++) {
        size_t min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            /* Print array after each swap */
            for (j = 0; j < size - 1; j++) {
                printf("%d, ", array[j]);
            }
            printf("%d\n", array[size - 1]);
        }
    }
}
