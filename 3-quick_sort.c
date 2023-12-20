#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to partition
 * @low: Lower bound of the partition
 * @high: Upper bound of the partition
 * @size: Size of the array
 * Return: Index of the pivot
 */
size_t lomuto_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

/**
 * quicksort - Quick sort recursive function
 * @array: Array to sort
 * @low: Lower bound of the partition
 * @high: Upper bound of the partition
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size) {
    if (low < high) {
        size_t pi = lomuto_partition(array, low, high, size);
        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

