#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N (1 << 16)

double a = 2.0, *x, *y;

double performer(int tc) {
    double start = omp_get_wtime();

    #pragma omp parallel for num_threads(tc)
    for (int i=0 ; i<N ; i++) {
        x[i] = a * x[i] + y[i];
    }

    return omp_get_wtime() - start;
}

int main() {
    x = (double*)malloc(N * sizeof(double));
    y = (double*)malloc(N * sizeof(double));
    int threads[] = {1, 2, 4, 8, 10};
    int count = 5;

    srand(42);
    for (int i=0 ; i<N ; i++) {
        x[i] = rand() % 1000;
        y[i] = rand() % 1000;
    }

    double times[count];

    printf("DAXPY: X[i] = a * X[i] + Y[i]\n");
    printf("N = %d\n\n", N);

    for (int i=0 ; i<count ; i++) {
        times[i] = performer(threads[i]);
        printf("Threads: %2d | Time: %.9f seconds\n", threads[i], times[i]);
    }

    printf("\nSpeedup:\n");
    for (int i=0 ; i<count ; i++) {
        printf("Threads: %2d | Speedup: %.2f\n", threads[i], times[0]/times[i]);
    }

    free(x);
    free(y);
    return 0;
}