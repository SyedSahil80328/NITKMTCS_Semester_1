#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int *a;
    int *aux;
    int start;
    int end;
} ThreadData;

typedef struct {
    int left;
    int right;
} Interval;

double serial, parallel;

void merge(int *a, int *aux, int left, int middle, int right) {

    int i, j, k = left;

    for (i=left, j=middle+1 ; i<=middle && j<=right ; ) {
        aux[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }

    for (; i<=middle ; i++) {
        aux[k++] = a[i];
    }

    for (; j<=right ; j++) {
        aux[k++] = a[j];
    }

    for (i=left ; i<=right ; i++) {
        a[i] = aux[i];
    }
}

void split(int *a, int *aux, int left, int right) {
    if (left < right) {
        int middle = (left+right)/2;

        split(a, aux, left, middle);
        split(a, aux, middle+1, right);

        merge(a, aux, left, middle, right);
    }
}

void* worker(void* arg) {
    ThreadData* td = (ThreadData*)arg;
    split(td->a, td->aux, td->start, td->end);
    return NULL;
}

void mergeIntervals(int *a, int *aux, Interval *intervals, int tc) {
    int count = tc;
    while (count > 1) {
        int newCount = 0;
        for (int i=0 ; i+1<count ; i+=2) {
            merge(a, aux, intervals[i].left, intervals[i].right, intervals[i+1].right);

            intervals[newCount].left = intervals[i].left;
            intervals[newCount].right = intervals[i+1].right;

            newCount++;
        }

        if (count % 2 != 0) {
            intervals[newCount] = intervals[count-1];
            newCount++;
        }

        count = newCount;
    }
}

void performer(int *a, int *aux, int n, int tc, char* msg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (tc == 1) {
        split(a, aux, 0, n-1);
    } else {
        ThreadData td[tc];
        pthread_t threads[tc];
        Interval intervals[tc];

        for (int i=0 ; i<tc ; i++) {
            td[i].a = a;
            td[i].aux = aux;
            td[i].start = i * (n/tc);
            td[i].end = (i+1) * (n/tc) - 1;

            intervals[i].left = td[i].start;
            intervals[i].right = td[i].end;
        }

        td[tc-1].end = n-1;
        intervals[tc-1].right = n-1;

        for (int i=0 ; i<tc ; i++) {
            pthread_create(&threads[i], NULL, worker, &td[i]);
        }

        for (int i=0 ; i<tc ; i++) {
            pthread_join(threads[i], NULL);
        }

        mergeIntervals(a, aux, intervals, tc);
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
}

int isSorted(int *a, int n) {
    for (int i=1 ; i<n ; i++) {
        if (a[i-1] > a[i]) {
            return 0;
        }
    }

    return 1;
}

int equal(int *a, int *b, int n) {
    for (int i=0 ; i<n ; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n = 10000;

    int *original = (int*)malloc(n*sizeof(int));
    int *sc = (int*)malloc(n*sizeof(int));
    int *pc = (int*)malloc(n*sizeof(int));
    int *saux = (int*)malloc(n*sizeof(int));
    int *paux = (int*)malloc(n*sizeof(int));

    srand(42);

    for (int i=0 ; i<n ; i++) {
        original[i] = rand() % 1000000;
    }

    for (int i=0 ; i<n ; i++) {
        sc[i] = original[i];
    }

    printf("Question 2: Serial and Parallel Merge Sort using Pthreads.\n\n");
    performer(sc, saux, n, 1, "Serial Execution");
    printf("Sorted: %s\n", isSorted(sc, n) ? "YES" : "NO");

    printf("\n");

    for (int i=0 ; i<n ; i++) {
        pc[i] = original[i];
    }

    performer(pc, paux, n, 4, "4 threaded Execution");
    printf("Sorted: %s\n", isSorted(pc, n) ? "YES" : "NO");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    for (int i=0 ; i<n ; i++) {
        pc[i] = original[i];
    }

    performer(pc, paux, n, 8, "8 threaded Execution");
    printf("Sorted: %s\n", isSorted(pc, n) ? "YES" : "NO");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    for (int i=0 ; i<n ; i++) {
        pc[i] = original[i];
    }

    performer(pc, paux, n, 12, "12 threaded Execution");
    printf("Sorted: %s\n", isSorted(pc, n) ? "YES" : "NO");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    for (int i=0 ; i<n ; i++) {
        pc[i] = original[i];
    }

    performer(pc, paux, n, 16, "16 threaded Execution");
    printf("Sorted: %s\n", isSorted(pc, n) ? "YES" : "NO");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    free(original);
    free(sc);
    free(pc);
    free(saux);
    free(paux);

    return 0;
}

// gcc question_02.c -o question_02 -pthread