#include <stdio.h>
#include <omp.h>

void printHello(int threadID) {
    printf("Hello World!\tPrinted by thread %d.\n", threadID);
}

int main () {
    /* Parallel region begins here */
    #pragma omp parallel 
    {
        printHello(omp_get_thread_num());
    }
}