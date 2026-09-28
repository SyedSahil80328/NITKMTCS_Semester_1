#include <stdio.h>
#include <omp.h>

#define N 1000000000

double performer(int tc) {
    double step = 1.0 / (double)N;
    double sum = 0.0;

    double start = omp_get_wtime();

    #pragma omp parallel for num_threads(tc) reduction(+:sum)
    for (int i=0 ; i<N ; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    double pi = step * sum;

    double elapsed = omp_get_wtime() - start;

    printf("Threads: %2d | Time: %.9f seconds | Pi: %.12f\n", tc, elapsed, pi);

    return elapsed;
}

int main() {
    int threads[] = {1, 2, 4, 8, 10};
    int count = 5;
    double times[count];

    printf("Calculation of Pi using Numerical Integration\n");
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