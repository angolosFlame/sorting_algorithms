#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        printf("Swapped: %d and %d\n", array[i], array[j]);
    }
}

/**
 * quick_sort_recursive - Recursive function for quick sort
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = hoare_partition(array, low, high);

        quick_sort_recursive(array, low, pivot_index);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers using Quick sort (Hoare's scheme)
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

/*int main()
{
    int arr[] = {3, 7, 4, 8, 6, 2, 1, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    quick_sort_hoare(arr, size);

    printf("\nSorted array:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/

