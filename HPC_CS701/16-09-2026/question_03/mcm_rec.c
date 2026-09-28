#include <stdio.h>
#include <limits.h>

int mcm_recursive(int *p, int i, int j) {
    if (i == j) {
        return 0;
    }

    int min_ops = INT_MAX;

    for (int k=i ; k<j ; k++) {
        int count = mcm_recursive(p, i, k) + mcm_recursive(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min_ops) {
            min_ops = count;
        }
    }

    return min_ops;
}

int main() {
    int arr[] = {5, 10, 15, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = 0;

    for (int iter=0 ; iter<10000000 ; iter++) {
        result = mcm_recursive(arr, 1, n - 1);
    }

    printf("Minimum scalar multiplications (Recursive): %d\n", result);

    return 0;
}
