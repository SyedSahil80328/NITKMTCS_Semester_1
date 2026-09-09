#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "q01_utils.h"

void* worker (void* arg) {
    ThreadData* data = (ThreadData*)arg;

    data->metrics.sum = findSum(data->arr, data->start, data->end);
    data->metrics.max = findMax(data->arr, data->start, data->end);
    data->metrics.min = findMin(data->arr, data->start, data->end);
    data->metrics.even = countEvenElements(data->arr, data->start, data->end);

    return NULL;
}

void performer(int *arr, int n, int threads, char* message) {
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    Output metrics;
    pthread_t thread[threads];
    ThreadData td[threads];

    for (int i=0 ; i<threads ; i++) {
        td[i].arr = arr;
        td[i].start = i * n/threads;
        td[i].end = (i+1) * n/threads;
        pthread_create(&thread[i], NULL, worker, &td[i]);
    }

    for (int i=0 ; i<threads ; i++) {
        pthread_join(thread[i], NULL);
    }

    metrics.sum = 0;
    metrics.even = 0;
    metrics.max = td[0].metrics.max;
    metrics.min = td[0].metrics.min;

    for (int i=0 ; i<threads ; i++) {
        metrics.sum += td[i].metrics.sum;
        metrics.even += td[i].metrics.even;
        metrics.max = (metrics.max < td[i].metrics.max) ? td[i].metrics.max : metrics.max;
        metrics.min = (metrics.min > td[i].metrics.min) ? td[i].metrics.min : metrics.min;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    
    printf("Result for %s process.\n", message);
    printResult(metrics, start, end);
}

int main () {
    size_t n = 1000000;
    int* arr = initializeArray(n);

    performer(arr, n, 1, "serial");
    performer(arr, n, 4, "4 threaded");
    performer(arr, n, 8, "8 threaded");
    performer(arr, n, 12, "12 threaded");
    performer(arr, n, 16, "16 threaded");

    printOverall();

    free(arr);
    return 0;
}