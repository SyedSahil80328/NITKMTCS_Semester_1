#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int **a;
    int **b;
    long long **c;

    int start;
    int end;
    int n;
} ThreadData;

void* worker (void* arg) {
    ThreadData* td = (ThreadData*)arg;

    for (int i=td->start ; i<td->end ; i++) {
        for (int j=0 ; j<td->n ; j++) {
            td->c[i][j] = 0;
            for (int k=0 ; k<td->n ; k++) {
                td->c[i][j] +=
                    (long long)td->a[i][k] * td->b[k][j];
            }
        }
    }

    return NULL;
}

double serial, parallel;

void performer (int **a, int **b, long long **c, int n, int tc, char* msg) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (tc == 1) {
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                c[i][j] = 0;
                for (int k=0 ; k<n ; k++) {
                    c[i][j] += (long long)a[i][k] * b[k][j];
                }
            }
        }
    } else {
        ThreadData td[tc];
        pthread_t threads[tc];

        for (int i=0 ; i<tc ; i++) {
            td[i].a = a;
            td[i].b = b;
            td[i].c = c;
            td[i].n = n;

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

int equal(long long **a, long long **b, int n) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (a[i][j] != b[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int isCorrect(int **a, int **b, long long **c, int n) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {

            long long result = 0;

            for (int k=0 ; k<n ; k++) {
                result +=
                    (long long)a[i][k] * b[k][j];
            }

            if (c[i][j] != result) {
                return 0;
            }
        }
    }

    return 1;
}

int** createIntMatrix(int n) {
    int **matrix = malloc(n * sizeof(int*));
    for (int i=0 ; i<n ; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    return matrix;
}

long long** createLongMatrix(int n) {
    long long **matrix = malloc(n * sizeof(long long*));
    for (int i=0 ; i<n ; i++) {
        matrix[i] = malloc(n * sizeof(long long));
    }
    return matrix;
}

void freeIntMatrix(int **matrix, int n) {
    for (int i=0 ; i<n ; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeLongMatrix(long long **matrix, int n) {
    for (int i=0 ; i<n ; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void testcase(int n) {
    printf("\n========================================\n");
    printf("Matrix Dimension: %d x %d\n", n, n);
    printf("========================================\n\n");

    int **a, **b;
    long long **sc, **pc;

    a = createIntMatrix(n);
    b = createIntMatrix(n);
    sc = createLongMatrix(n);
    pc = createLongMatrix(n);

    srand(42);

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            a[i][j] = rand() % 1000;
            b[i][j] = rand() % 1000;
        }
    }

    performer(a, b, sc, n, 1, "Serial Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, sc, n) ? "PASS" : "FAIL");
    printf("\n");

    performer(a, b, pc, n, 4, "4 threaded Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, pc, n) ? "PASS" : "FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    performer(a, b, pc, n, 8, "8 threaded Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, pc, n) ? "PASS" : "FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    performer(a, b, pc, n, 16, "16 threaded Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, pc, n) ? "PASS" : "FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    performer(a, b, pc, n, 32, "32 threaded Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, pc, n) ? "PASS" : "FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    performer(a, b, pc, n, 64, "64 threaded Execution");
    // printf("Correctness: %s\n", isCorrect(a, b, pc, n) ? "PASS" : "FAIL");
    printf("Equality of parallel and serial: %s.\n\n", equal(sc, pc, n) ? "YES" : "NO");

    freeIntMatrix(a, n);
    freeIntMatrix(b, n);
    freeLongMatrix(sc, n);
    freeLongMatrix(pc, n);
}

int main () {
    printf("Question 4: Serial and Parallel Matrix Multiplication using Pthreads.\n\n");
    testcase(512);
    testcase(1024);
    testcase(2048);

    return 0;
}

// gcc question_04.c -o question_04 -pthread