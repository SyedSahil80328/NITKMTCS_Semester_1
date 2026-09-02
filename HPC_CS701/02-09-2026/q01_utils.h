#include <stdlib.h>
#include <limits.h>

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