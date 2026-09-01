#include <iostream>
using namespace std;

class Heap {
    int *heap;
    int size;

    public:
        Heap (int *heap, int size) {
            this->heap = heap;
            this->size = size;
        }

        void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        void minHeapify(int i) {
            int left = (i << 1) + 1;
            int right = (i << 1) + 2;
            int smallest;

            if (left < size and heap[left] < heap[i]) {
                smallest = left;
            } else {
                smallest = i;
            }

            if (right < size and heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (i != smallest) {
                swap(i, smallest);
                minHeapify(smallest);
            }
        }

        int pop() {
            int s = heap[0];
            swap(0, --size);
            minHeapify(0);
            return s;
        }

        void buildMinHeap() {
            for (int i=(size-1)/2 ; i>=0 ; i--) {
                minHeapify(i);
            }
        }

        void printHeap() {
            for (int i=0 ; i<size ; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main () {
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    Heap heapObject(arr, 10);
    heapObject.buildMinHeap();
    heapObject.printHeap();
    int min = heapObject.pop();
    cout << min << endl;
    heapObject.printHeap();
}