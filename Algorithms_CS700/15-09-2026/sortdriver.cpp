#include <iostream>
#include <cstdlib>
#include "../modules/sorting.h"
using namespace std;

void copy (int* source, int* dest, int slen) {
    for (int i=0 ; i<slen ; i++) {
        dest[i] = source[i];
    }
}

int main () {
    int n = 100000000;
    int *org = new int[n];
    int *arr = new int[n];

    srand(42);
    for (int i=0 ; i<n ; i++) {
        org[i] = rand();
    }
    copy(org, arr, n);
    
    Sorting s;
    s.merge_sort(arr, n);

    printf("Merge Sort completed.\n");
    printf("Sorted: %s.\n", s.sorted(arr, n));

    copy(org, arr, n);

    s.quick_sort(arr, n);
    printf("\nQuick Sort completed.\n");
    printf("Sorted: %s.\n", s.sorted(arr, n));
}