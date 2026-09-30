#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

double performer(int tc) {
    long inside = 0;

    double start = omp_get_wtime();

    #pragma omp parallel num_threads(tc)
    {
        unsigned int seed = 42 + omp_get_thread_num();
        long local_inside = 0;

        #pragma omp for
        for (long i=0 ; i<N ; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX;
            double y = (double)rand_r(&seed) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                local_inside++;
            }
        }

        #pragma omp atomic
        inside += local_inside;
    }

    double pi = 4.0 * (double)inside / N;

    double elapsed = omp_get_wtime() - start;

    printf("Threads: %2d | Time: %.9f seconds | Pi: %.12f\n", tc, elapsed, pi);

    return elapsed;
}

int main() {
    int threads[] = {1, 2, 4, 8, 10};
    int count = 5;
    double times[count];

    printf("Calculation of Pi using Monte Carlo Simulation\n");
    printf("N = %d\n\n", N);

    for (int i=0 ; i<count ; i++) {
        times[i] = performer(threads[i]);
    }

    printf("\nSpeedup:\n");

    for (int i=0 ; i<count ; i++) {
        printf("Threads: %2d | Speedup: %.2f\n", threads[i], times[0]/times[i]);
    }

    return 0;
}