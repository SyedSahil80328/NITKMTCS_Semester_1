struct Edge {
    int vertexU;
    int vertexV;
    int weight;
};

class Heap {
    Edge *heap;
    int size;

    public:
        Heap (Edge *heap, int size) {
            this->heap = heap;
            this->size = size;
        }

        void swap(int i, int j) {
            Edge temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        void minHeapify(int i) {
            int left = (i << 1) + 1;
            int right = (i << 1) + 2;
            int smallest;

            if (left < size && getWeight(left) < getWeight(i)) {
                smallest = left;
            } else {
                smallest = i;
            }

            if (right < size && getWeight(right) < getWeight(smallest)) {
                smallest = right;
            }

            if (i != smallest) {
                swap(i, smallest);
                minHeapify(smallest);
            }
        }

        Edge pop() {
            if (size == 0) {
                Edge error;
                error.vertexU = error.vertexV = error.weight = -1;
                return error;
            }
            Edge s = heap[0];
            swap(0, --size);
            minHeapify(0);
            return s;
        }

        void buildMinHeap() {
            for (int i=(size-1)/2 ; i>=0 ; i--) {
                minHeapify(i);
            }
        }

        Edge* getHeap() {
            return heap;
        }

        int getWeight(int index) {
            return heap[index].weight;
        }
};