#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

double *a;
double sum = 0.0;
int flag = 0;

void producer() {
    for (int i=0 ; i<N ; i++) {
        a[i] = rand() % 100;
    }

    flag = 1;
    #pragma omp flush(flag)
}

void consumer() {
    while (1) {
        #pragma omp flush(flag)
        if (flag == 1) {
            break;
        }
    }

    for (int i=0 ; i<N ; i++) {
        sum += a[i];
    }
}

int main() {
    a = (double*)malloc(N * sizeof(double));

    double start = omp_get_wtime();

    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            producer();

            #pragma omp section
            consumer();
        }
    }

    double elapsed = omp_get_wtime() - start;

    printf("Producer-Consumer Program\n");
    printf("Array size: %d\n", N);
    printf("Sum: %.2f\n", sum);
    printf("Time: %.9f seconds\n", elapsed);

    free(a);

    return 0;
}