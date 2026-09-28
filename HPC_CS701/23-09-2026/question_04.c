#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N 2000

int main() {
    printf("===================================================\n");
    printf("  OpenMP Matrix Multiplication (N = %d x %d)\n", N, N);
    printf("===================================================\n\n");

    double (*A)[N] = malloc(sizeof(double[N][N]));
    double (*B)[N] = malloc(sizeof(double[N][N]));
    double (*C_serial)[N] = malloc(sizeof(double[N][N]));
    double (*C_parallel)[N] = malloc(sizeof(double[N][N]));

    if (!A || !B || !C_serial || !C_parallel) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }

    printf("Initializing matrices (%d x %d)...\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j) * 0.001;
            B[i][j] = (double)(i - j) * 0.001;
            C_serial[i][j] = 0.0;
            C_parallel[i][j] = 0.0;
        }
    }

    printf("\nStarting Serial Matrix Multiplication...\n");
    double start_time = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C_serial[i][j] = sum;
        }
    }

    double end_time = omp_get_wtime();
    double t_serial = end_time - start_time;
    printf("Serial Time (T1): %.4f seconds\n", t_serial);

    int num_threads = omp_get_max_threads();
    printf("\nStarting Parallel Matrix Multiplication with %d OpenMP threads...\n", num_threads);
    start_time = omp_get_wtime();

    #pragma omp parallel for collapse(2) schedule(static)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C_parallel[i][j] = sum;
        }
    }

    end_time = omp_get_wtime();
    double t_parallel = end_time - start_time;
    printf("Parallel Time (Tp with %d threads): %.4f seconds\n", num_threads, t_parallel);

    double speedup = t_serial / t_parallel;
    printf("Speedup (S_p = T1 / Tp): %.2fx\n", speedup);

    int correct = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fabs(C_serial[i][j] - C_parallel[i][j]) > 1e-5) {
                correct = 0;
                break;
            }
        }
        if (!correct) break;
    }

    if (correct) {
        printf("\nResult Verification: SUCCESS (Parallel output matches Serial output!)\n");
    } else {
        printf("\nResult Verification: FAILED (Mismatch between Serial and Parallel outputs)\n");
    }

    free(A);
    free(B);
    free(C_serial);
    free(C_parallel);

    return 0;
}
