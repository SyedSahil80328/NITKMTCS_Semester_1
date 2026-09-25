#include <stdio.h>
#include <omp.h>

int main () {
    /* Parallel region begins here */
    #pragma omp parallel 
    {
        printf("Hello World!\n");
    }
}