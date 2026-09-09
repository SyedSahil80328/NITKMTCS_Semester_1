#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

int* initializeArray (size_t n) {
    int* arr = malloc(n * sizeof(int));

    srand(42);
    for (size_t i=0 ; i<n ; i++) {
        arr[i] = rand() % 200;
    }

    return arr;
}

void split(int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        split(l, m);
        split(m+1, r);
        merge(l, m, r);
    }
}

void merge(int *arr, int *aux, int l1, int l2, int r1, int r2, bool turn) {
    int i, j, k=l1;
    int *funmain, *funaux;
    if (turn) {
        funmain = arr;
        funaux = aux;
    } else {
        funmain = aux;
        funaux = arr;
    }

    for (i=l1, j=r1; i<=l2 && j<=r2 ; ) {
        if (funmain[i] < funmain[j]) {
            funaux[k++] = funmain[i++];
        } else {
            funaux[k++] = funmain[j++];
        }
    }
    for ( ; i<=l2 ; i++) {
        funaux[k++] = funmain[i++];
    }
    for ( ; j<=r2 ; j++) {
        funaux[k++] = funmain[j++];
    }
}

int main() {
    size_t n = 50;
    int *arr, *aux;

    arr = initializeArray(n);
    aux = malloc(n * sizeof(int));

    int groupsize = 1;
    bool turn = true;

    while (groupsize < n) {

        for (int start = 0; start + groupsize < n; start += 2 * groupsize) {

            int l1 = start;
            int l2 = start + groupsize - 1;

            // No second group → just copy remaining elements
            if (l2 >= n) {
                l2 = n - 1;

                int *src  = turn ? arr : aux;
                int *dest = turn ? aux : arr;

                for (int i = l1; i <= l2; i++)
                    dest[i] = src[i];

                continue;
            }

            int r1 = start + groupsize;
            int r2 = start + 2 * groupsize - 1;

            if (r2 >= n)
                r2 = n - 1;

            merge(arr, aux, l1, l2, r1, r2, turn);
        }

        groupsize *= 2;
        turn = !turn;
    }

    /* If final result is in aux, copy it back */
    if (!turn) {
        for (int i = 0; i < n; i++)
            arr[i] = aux[i];
    }

    for (int i=0 ; i<n ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(aux);

    return 0;
}