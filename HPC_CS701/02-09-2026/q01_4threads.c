#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "q01_utils.h"

typedef struct {
    int *arr;
    size_t n;
    size_t start;
    size_t end;

    int max;
    int min;
    int sum;
    int even;
}ThreadData;

void* worker (void* arg) {
    ThreadData* data = (ThreadData*)arg;


}

int main () {
    size_t n = 1000000;
    int* arr = initializeArray(n);

    ThreadData threadData[4];
    int max, min, sum, even;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    sum = findSum(arr, 0, n);
    max = findMax(arr, 0, n);
    min = findMin(arr, 0, n);
    even = countEvenElements(arr, 0, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Sum of 1 million numbers: %d.\n", sum);
    printf("Max of 1 million numbers: %d.\n", max);
    printf("Min of 1 million numbers: %d.\n", min);
    printf("Even numbers among of 1 million numbers: %d.\n\n", even);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Execution time: %.9f seconds.\n", elapsed);

    free(arr);
    return 0;
}