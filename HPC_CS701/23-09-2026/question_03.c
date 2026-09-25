#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define size 50000000

int main () {
    /* Parallel region begins here */
    double *x = (double*)malloc(size*sizeof(double));
    double *y = (double*)malloc(size*sizeof(double));
    double *z = (double*)malloc(size*sizeof(double));
    double a = 2.5;

    for (int i=0 ; i<size ; i++) {
        x[i] = 1.0;
        y[i] = 2.0;
    }

    #pragma omp parallel for
    for (int i=0 ; i<size ; i++) {
        z[i] = a * x[i] + y[i];
    }

    free(x);
    free(y);
    free(z);
}