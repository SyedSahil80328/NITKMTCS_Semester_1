#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
};

Interval *auxiliary;
void merge(Interval* arr, int start, int middle, int end) {
    int i1, i2, i3;
    for (i1 = start, i2 = middle + 1, i3 = start; i1 <= middle && i2 <= end; i3++) {
        if (arr[i1].end < arr[i2].end) {
            auxiliary[i3] = arr[i1++];
        } else if (arr[i1].end == arr[i2].end) {
            if (arr[i1].start <= arr[i2].start) {
                auxiliary[i3] = arr[i1++];
            } else {
                auxiliary[i3] = arr[i2++];
            }
        } else {
            auxiliary[i3] = arr[i2++];
        }
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

void divide_and_conquer(Interval* arr, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;
        divide_and_conquer(arr, start, middle);
        divide_and_conquer(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void merge_sort(Interval* arr, int n) {
    if (n <= 1) return;
    auxiliary = new Interval[n];
    divide_and_conquer(arr, 0, n - 1);
    delete[] auxiliary;
}

int main () {
    int n;
    Interval *intervals;

    cin >> n;
    intervals = new Interval[n];

    for (int i=0 ; i<n ; i++) {
        int st, en;
        cin >> st >> en;
        intervals[i].start = st;
        intervals[i].end = en;
    }

    merge_sort(intervals, n);
    cout << "Given Set of intervals (Non-decreasing order according to finish time): ";
    for (int i=0 ; i<n ; i++) {
        cout << "(" << intervals[i].start << ", " << intervals[i].end << ") ";
    }
    cout << endl;

    Interval* mISIntervals = new Interval[n];
    mISIntervals[0] = intervals[0];
    Interval curr = intervals[0];
    int r = 1;

    for (int i=1 ; i<n ; i++) {
        if (curr.end < intervals[i].start) {
            curr = intervals[i];
            mISIntervals[r++] = curr;
        }
    }

    cout << "One of the Maximum Independent Sets of Intervals: ";
    for (int i=0 ; i<r ; i++) {
        cout << "(" << mISIntervals[i].start << ", " << mISIntervals[i].end << ") ";
    }
    cout << endl << "The MIS length is " << r << ".\n"; 
    
    delete[] intervals;
    delete[] mISIntervals;
    return 0;
}