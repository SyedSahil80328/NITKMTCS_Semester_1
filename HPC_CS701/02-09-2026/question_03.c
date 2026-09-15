#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int *a;
    int *b;
    int *c;

    int start;
    int end;
} ThreadData;

void* worker (void* arg) {
    ThreadData* td = (ThreadData*)arg;

    for (int i=td->start ; i<td->end ; i++) {
        td->c[i] = td->a[i] + td->b[i];
    }

    return NULL;
}

double serial, parallel;

void performer (int *a, int *b, int *c, int n, int tc, char* msg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (tc == 1) {
        for (int i=0 ; i<n ; i++) {
            c[i] = a[i] + b[i];
        }
    } else {
        ThreadData td[tc];
        pthread_t threads[tc];

        for (int i=0 ; i<tc ; i++) {
            td[i].a = a;
            td[i].b = b;
            td[i].c = c;

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

int equal(int *a, int *b, int n) {
    for (int i=0 ; i<n ; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int isCorrect(int *a, int *b, int *c, int n) {
    for (int i=0; i<n; i++) {
        if (c[i] != a[i]+b[i]) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int n = 10000;
    int *a, *b, *sc, *pc;

    a = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(n*sizeof(int));
    sc = (int*)malloc(n*sizeof(int));
    pc = (int*)malloc(n*sizeof(int));

    srand(42);

    for (int i=0 ; i<n ; i++) {
        a[i] = rand() % 1000000;
        b[i] = rand() % 1000000;
    }

    performer(a, b, sc, n, 1, "Serial Execution");
    printf("Correctness: %s\n", isCorrect(a, b, sc, n)?"PASS":"FAIL");
    printf("\n");
    performer(a, b, pc, n, 4, "4 threaded Execution");
    printf("Correctness: %s\n", isCorrect(a, b, pc, n)?"PASS":"FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n)?"YES":"NO");
    performer(a, b, pc, n, 8, "8 threaded Execution");
    printf("Correctness: %s\n", isCorrect(a, b, pc, n)?"PASS":"FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n)?"YES":"NO");
    performer(a, b, pc, n, 12, "12 threaded Execution");
    printf("Correctness: %s\n", isCorrect(a, b, pc, n)?"PASS":"FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n)?"YES":"NO");
    performer(a, b, pc, n, 16, "16 threaded Execution");
    printf("Correctness: %s\n", isCorrect(a, b, pc, n)?"PASS":"FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n)?"YES":"NO");

    free(a);
    free(b);
    free(sc);
    free(pc);

    return 0;
}