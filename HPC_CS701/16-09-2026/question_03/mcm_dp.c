#include <stdio.h>
#include <limits.h>

#define MAX_MAT 100

int mcm_dp(int *p, int n) {
    int m[MAX_MAT][MAX_MAT];

    for (int i=1 ; i<n ; i++) {
        m[i][i] = 0;
    }

    for (int L=2 ; L<n ; L++) {
        for (int i=1 ; i<n-L+1 ; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k=i ; k<=j-1 ; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr[] = {5, 10, 15, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = 0;

    for (int iter=0 ; iter<50000000 ; iter++) {
        result = mcm_dp(arr, n);
    }

    printf("Minimum scalar multiplications (Dynamic Programming): %d\n", result);

    return 0;
}
