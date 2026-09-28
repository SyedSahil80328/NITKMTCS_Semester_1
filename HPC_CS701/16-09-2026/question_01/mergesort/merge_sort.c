#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i=0 ; i<n1 ; i++) L[i] = arr[l + i];
    for (int j=0 ; j<n2 ; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int *arr = (int*)malloc(SIZE * sizeof(int));
    if (!arr) return 1;

    srand(42);

    for (int i=0 ; i<SIZE ; i++) {
        arr[i] = rand() % 100000;
    }

    merge_sort(arr, 0, SIZE - 1);

    printf("Merge Sort completed for N = %d elements.\n", SIZE);
    printf("First 5 sorted elements: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    free(arr);

    return 0;
}
