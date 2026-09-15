#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int sum;
    int max;
    int min;
    int even;
} Output;

typedef struct {
    int *a;
    int start;
    int end;
    Output metrics;
} ThreadData;

Output metricsS, metricsP;
double serial, parallel;

int* initializeArray(int n) {
    int *a = (int*)malloc(n * sizeof(int));

    srand(42);

    for (int i=0 ; i<n ; i++) {
        a[i] = rand() % 1000;
    }

    return a;
}

Output slave(int *arr, int start, int end) {
    Output metrics;
    metrics.even = 0;
    metrics.max = -1;
    metrics.min = INT_MAX;
    metrics.sum = 0;

    for (int i=start ; i<end ; i++) {
        metrics.sum += arr[i];
        metrics.max = (metrics.max < arr[i]) ? arr[i] : metrics.max;
        metrics.min = (metrics.min > arr[i]) ? arr[i] : metrics.min;
        metrics.even += !(arr[i] & 1);
    }

    return metrics;
}

void* worker(void* arg) {
    ThreadData* td = (ThreadData*)arg;
    td->metrics = slave(td->a, td->start, td->end);
    return NULL;
}

void printMetrics(Output metrics) {
    printf("Sum: %d\n", metrics.sum);
    printf("Max: %d\n", metrics.max);
    printf("Min: %d\n", metrics.min);
    printf("Even numbers: %d\n", metrics.even);
}

void performer(int *a, int n, int tc, char* msg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    Output metrics;

    if (tc == 1) {
        metricsS = slave(a, 0, n);
    } else {
        ThreadData td[tc];
        pthread_t threads[tc];

        for (int i=0 ; i<tc ; i++) {
            td[i].a = a;
            td[i].start = i * (n/tc);
            td[i].end = (i+1) * (n/tc);
        }

        td[tc-1].end = n;

        for (int i=0 ; i<tc ; i++) {
            pthread_create(&threads[i], NULL, worker, &td[i]);
        }

        for (int i=0 ; i<tc ; i++) {
            pthread_join(threads[i], NULL);
        }

        metrics.sum = 0;
        metrics.even = 0;
        metrics.max = td[0].metrics.max;
        metrics.min = td[0].metrics.min;

        for (int i=0 ; i<tc ; i++) {
            metrics.sum += td[i].metrics.sum;
            metrics.even += td[i].metrics.even;
            metrics.max = (metrics.max < td[i].metrics.max) ? td[i].metrics.max : metrics.max;
            metrics.min = (metrics.min > td[i].metrics.min) ? td[i].metrics.min : metrics.min;
        }

        metricsP = metrics;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (tc == 1) {
        serial = elapsed;
        parallel = elapsed;
    } else {
        parallel = elapsed;
    }

    printf("Result for %s: %.9f secs.\n", msg, elapsed);
    printf("Speed-up achieved: %.2f\n", serial/parallel);

    if (tc == 1) {
        printf("Serial Result:\n");
        printMetrics(metricsS);
    }
}

int equal() {
    return (metricsP.sum == metricsS.sum) && (metricsP.max == metricsS.max) && (metricsP.min == metricsS.min) && (metricsP.even == metricsS.even);
}

int main() {
    int n = 1000000;
    int *a = initializeArray(n);

    performer(a, n, 1, "Serial Execution");

    printf("\n");

    performer(a, n, 4, "4 threaded Execution");
    printf("Equality of parallel and serial: %s.\n\n", equal() ? "YES" : "NO");

    performer(a, n, 8, "8 threaded Execution");
    printf("Equality of parallel and serial: %s.\n\n", equal() ? "YES" : "NO");

    performer(a, n, 12, "12 threaded Execution");
    printf("Equality of parallel and serial: %s.\n\n", equal() ? "YES" : "NO");

    performer(a, n, 16, "16 threaded Execution");
    printf("Equality of parallel and serial: %s.\n\n", equal() ? "YES" : "NO");

    free(a);

    return 0;
}

// gcc question_01.c -o question_01 -pthread