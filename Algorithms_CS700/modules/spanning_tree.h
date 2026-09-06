#include <iostream>
#include "heap.h"
using namespace std;

class MSTAlgorithms {
    Edge *edges;
    int edgeCount, index;
    
    public:
        MSTAlgorithms(int edgeCount) {
            this->edges = new Edge[edgeCount];
            this->edgeCount = edgeCount;
            this->index = 0;
        }

        void addEdge(int u, int v, int weight) {
            edges[index].vertexU = u;
            edges[index].vertexV = v;
            edges[index].weight = weight;
            index++;
        }

        void printEdges() {
            for (int i=0 ; i<edgeCount ; i++) {
                cout << edges[i].vertexU << ", " << edges[i].vertexV << ", " << edges[i].weight << endl;
            }
            cout << endl;
        }

        void kruskal() {
            Heap h(edges, edgeCount);
            h.buildMinHeap();
            this->printEdges();
        }
};