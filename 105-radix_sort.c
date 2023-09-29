#include "sort.h"

/**
 * A function that sorts an array of integers in ascending order 
 * using the Radix sort algorithm
 */

int get_max(int *array, size_t size) {
    int max = array[0];
    size_t i=0, j=1;
    for (; j < size; j++) {
        if (array[j] > max)
            max = array[j];
    }
    return max;
}

void counting_sort(int *array, size_t size, int exp) {
    int output[size];
    int count[10] = {0};
    int n = 1;
    size_t i = 0;
    int t = size-1;

    for (; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (; n < 10; n++) {
        count[n] += count[n - 1];
    }
	
    for (; t >= 0; t--) {
        output[count[(array[t] / exp) % 10] - 1] = array[t];
        count[(array[t] / exp) % 10]--;
    }

    for (; i < size; i++) {
        array[i] = output[i];
    }
}

void radix_sort(int *array, size_t size) {
    int max = get_max(array, size), exp;

    for (exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(array, size, exp);
    }
}
