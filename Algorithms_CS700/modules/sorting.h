#pragma once

class Sorting {
private:
    int* auxiliary;
    const char* yes = "YES";
    const char* no = "NO";

    void swap_val(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // --- Merge Sort Helpers ---
    void merge(int* arr, int start, int middle, int end) {
        int i1, i2, i3;
        for (i1 = start, i2 = middle + 1, i3 = start; i1 <= middle && i2 <= end; i3++) {
            auxiliary[i3] = (arr[i1] <= arr[i2]) ? arr[i1++] : arr[i2++];
        }
        for (; i1 <= middle; i1++, i3++) {
            auxiliary[i3] = arr[i1];
        }
        for (; i2 <= end; i2++, i3++) {
            auxiliary[i3] = arr[i2];
        }

        for (i3 = start; i3 <= end; i3++) {
            arr[i3] = auxiliary[i3];
        }
    }

    void divide_and_conquer(int* arr, int start, int end) {
        if (start < end) {
            int middle = start + (end - start) / 2;
            divide_and_conquer(arr, start, middle);
            divide_and_conquer(arr, middle + 1, end);
            merge(arr, start, middle, end);
        }
    }

    // --- Quick Sort Helpers ---
    int partition(int* arr, int low, int high) {
        int pivot = arr[low + (high - low) / 2];
        int i = low - 1;
        int j = high + 1;
        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j) return j;
            swap_val(arr[i], arr[j]);
        }
    }

    void quick_sort_recursive(int* arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quick_sort_recursive(arr, low, p);
            quick_sort_recursive(arr, p + 1, high);
        }
    }

public:
    void merge_sort(int* arr, int n) {
        if (n <= 1) return;
        auxiliary = new int[n];
        divide_and_conquer(arr, 0, n - 1);
        delete[] auxiliary;
    }

    void quick_sort(int* arr, int n) {
        if (n <= 1) return;
        quick_sort_recursive(arr, 0, n - 1);
    }

    const char* sorted(int* arr, int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                return no;
            }
        }
        return yes;
    }
};
