#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 2000

double a[N][N];
double b[N][N];
double c[N][N];

double performer(int tc) {
    double start = omp_get_wtime();

    #pragma omp parallel for num_threads(tc)
    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            c[i][j] = 0.0;
            for (int k=0 ; k<N ; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return omp_get_wtime() - start;
}

int main() {
    int threads[] = {1, 2, 4, 8, 10};
    int count = 5;

    srand(42);

    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }

    double times[count];

    printf("Matrix Multiplication: C = A * B\n");
    printf("Matrix size: %d x %d\n\n", N, N);

    for (int i=0 ; i<count ; i++) {
        times[i] = performer(threads[i]);
        printf("Threads: %2d | Time: %.9f seconds\n", threads[i], times[i]);
    }

    printf("\nSpeedup:\n");

    for (int i=0 ; i<count ; i++) {
        printf("Threads: %2d | Speedup: %.2f\n", threads[i], times[0]/times[i]);
    }

    return 0;
}