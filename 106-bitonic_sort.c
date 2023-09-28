#include "sort.h"

/**
 * a function that sorts an array of integers in ascending order 
 * using the Bitonic sort algorithm
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void compare_and_swap(int *array, size_t size, int i, int j, int dir) {
    if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0)) {
        // Swap elements
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        printf("Swapped: %d and %d\n", array[i], array[j]);
    }
}

void bitonic_merge(int *array, size_t size, int dir) {
    if (size > 1) {
        int mid = size / 2;
        for (int i = 0; i < mid; i++) {
            compare_and_swap(array, size, i, i + mid, dir);
        }
        bitonic_merge(array, mid, dir);
        bitonic_merge(array + mid, mid, dir);
    }
}

void bitonic_sort_recursive(int *array, size_t size, int dir) {
    if (size > 1) {
        int mid = size / 2;

        // Sort in ascending order
        bitonic_sort_recursive(array, mid, 1);

        // Sort in descending order
        bitonic_sort_recursive(array + mid, mid, 0);

        // Merge the entire sequence
        bitonic_merge(array, size, dir);
    }
}

void bitonic_sort(int *array, size_t size) {
    bitonic_sort_recursive(array, size, 1);
}

/*int main() {
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    bitonic_sort(arr, size);

    printf("\nSorted array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/

