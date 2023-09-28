#include "sort.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

void quick_sort_recursive(int* array, int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);

        printf("Swapped: %d and %d\n", array[pivot_index], array[high]);

        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

void quick_sort_hoare(int* array, size_t size) {
    quick_sort_recursive(array, 0, size - 1);
}

int main() {
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quick_sort_hoare(arr, size);

    printf("\nSorted array:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

