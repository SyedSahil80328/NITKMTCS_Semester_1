#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low ; j<=high-1 ; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int *arr = (int*)malloc(SIZE * sizeof(int));
    if (!arr) return 1;

    srand(42);

    for (int i=0 ; i<SIZE ; i++) {
        arr[i] = rand() % 100000;
    }

    quick_sort(arr, 0, SIZE - 1);

    printf("Quick Sort completed for N = %d elements.\n", SIZE);
    printf("First 5 sorted elements: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    free(arr);

    return 0;
}