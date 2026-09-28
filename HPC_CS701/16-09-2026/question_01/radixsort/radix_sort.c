#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int get_max(int *arr, int n) {
    int mx = arr[0];

    for (int i=1 ; i<n ; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    return mx;
}

void count_sort(int *arr, int n, int exp) {
    int *output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i=0 ; i<n ; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i=1 ; i<10 ; i++) {
        count[i] += count[i - 1];
    }

    for (int i=n-1 ; i>=0 ; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i=0 ; i<n ; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radix_sort(int *arr, int n) {
    int m = get_max(arr, n);

    for (int exp=1 ; m/exp>0 ; exp*=10) {
        count_sort(arr, n, exp);
    }
}

int main() {
    int *arr = (int*)malloc(SIZE * sizeof(int));
    if (!arr) return 1;

    srand(42);

    for (int i=0 ; i<SIZE ; i++) {
        arr[i] = rand() % 100000;
    }

    radix_sort(arr, SIZE);

    printf("Radix Sort completed for N = %d elements.\n", SIZE);
    printf("First 5 sorted elements: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    free(arr);

    return 0;
}
