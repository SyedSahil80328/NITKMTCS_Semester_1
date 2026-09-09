#include <stdlib.h>
#include <limits.h>

typedef struct {
    int max;
    int min;
    int sum;
    int even;
}Output;

typedef struct {
    int *arr;
    size_t n;
    size_t start;
    size_t end;

    Output metrics;
}ThreadData;

double timing[5];
int tcs[] = {1, 4, 8, 12, 16};
int curr;
int* initializeArray (size_t n) {
    int* arr = malloc(n * sizeof(int));

    srand(42);
    for (size_t i=0 ; i<n ; i++) {
        arr[i] = rand() % 1000;
    }

    return arr;
}

int findSum(int *arr, int start, int end) {
    int total = 0;
    for (size_t i=start ; i<end ; i++) {
        total += arr[i];
    }
    return total;
}

int findMax(int *arr, int start, int end) {
    int max = -1;
    for (size_t i=start ; i<end ; i++) {
        max = (max < arr[i])?arr[i]:max;
    }
    return max;
}

int findMin(int *arr, int start, int end) {
    int min = INT_MAX;
    for (size_t i=start ; i<end ; i++) {
        min = (min > arr[i])?arr[i]:min;
    }
    return min;
}

int countEvenElements(int *arr, int start, int end) {
    int evenNumbers = 0;
    for (size_t i=start ; i<end ; i++) {
        evenNumbers = evenNumbers + !(arr[i]&1);
    }
    return evenNumbers;
}

void printResult(Output metrics, struct timespec start, struct timespec end) {
    printf("Sum of 1 million numbers: %d.\n", metrics.sum);
    printf("Max of 1 million numbers: %d.\n", metrics.max);
    printf("Min of 1 million numbers: %d.\n", metrics.min);
    printf("Even numbers among of 1 million numbers: %d.\n\n", metrics.even);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Execution time: %.9f seconds.\n\n", elapsed);
    timing[curr++] = elapsed;
}

void printOverall() {
    printf("Overall:\n");
    for (int i=0 ; i<5 ; i++) {
        printf("%d threads: %.9f secs.\n", tcs[i], timing[i]);
    }
}