#include <iostream>
#include "heap.h"
using namespace std;

int main () {
    Edge edges[7];

    edges[0] = {0, 1, 7};
    edges[1] = {0, 2, 6};
    edges[2] = {2, 3, 10};
    edges[3] = {2, 4, 14};
    edges[4] = {1, 4, 10};
    edges[5] = {1, 2, 16};
    edges[6] = {1, 3, 27};

    Heap heapObject(edges, 7);
    heapObject.buildMinHeap();

    for (int i=0 ; i<7 ; i++) {
        cout << edges[i].vertexU << ", " << edges[i].vertexV << ", " << edges[i].weight << endl;
    }
}