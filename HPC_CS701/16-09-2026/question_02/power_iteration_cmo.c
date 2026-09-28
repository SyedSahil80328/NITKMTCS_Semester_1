#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define TOL 1e-6
#define MAX_ITER 1000

int main() {
    double *M = (double*)malloc(N * N * sizeof(double));
    double *v = (double*)malloc(N * sizeof(double));
    double *b = (double*)malloc(N * sizeof(double));

    if (!M || !v || !b) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(42);

    for (int x=0 ; x<N ; x++) {
        for (int y=x ; y<N ; y++) {
            double val = (double)rand() / RAND_MAX;
            M[x * N + y] = val;
            M[y * N + x] = val;
        }
    }

    for (int i=0 ; i<N ; i++) {
        b[i] = (double)rand() / RAND_MAX;
    }

    double lambda_prev = 0.0;
    double lambda_curr = 0.0;

    for (int iter=0 ; iter<MAX_ITER ; iter++) {
        double norm = 0.0;

        for (int i=0 ; i<N ; i++) {
            norm += b[i] * b[i];
        }

        norm = sqrt(norm);
        lambda_curr = norm;

        for (int i=0 ; i<N ; i++) {
            v[i] = b[i] / norm;
        }

        if (fabs(lambda_curr - lambda_prev) < TOL) {
            printf("Col-Major Power Iteration converged in %d iterations.\n", iter);
            break;
        }

        lambda_prev = lambda_curr;

        for (int x=0 ; x<N ; x++) {
            b[x] = 0.0;
            for (int y=0 ; y<N ; y++) {
                b[x] += M[y * N + x] * v[y];
            }
        }
    }

    printf("Largest Eigenvalue (Col-Major Variant): %.6f\n", lambda_curr);

    free(M);
    free(v);
    free(b);

    return 0;
}
