#include "graph.h"
#include "spanning_tree.h"

int main() {
    Graph undirectedGraph(6, false);
    undirectedGraph.addEdge(0, 1, 3);
    undirectedGraph.addEdge(0, 2, 2);
    undirectedGraph.addEdge(0, 3, 8);
    undirectedGraph.addEdge(1, 2, 6);
    undirectedGraph.addEdge(1, 4, 4);
    undirectedGraph.addEdge(2, 4, 4);
    undirectedGraph.addEdge(2, 3, 7);
    undirectedGraph.addEdge(4, 5, 9);
    undirectedGraph.addEdge(2, 5, 8);
    cout << "Edges recorded: " << undirectedGraph.getEdges() << endl;

    MSTAlgorithms mst(undirectedGraph.getEdges());
    for (int i=0 ; i<6 ; i++) {
        Node* temp = undirectedGraph.getAdjacencyList(i);
        while (temp != NULL) {
            if (i < temp->vertex) {
                mst.addEdge(i, temp->vertex, temp->weight);
            }
            temp = temp->next;
        }
    }
    mst.kruskal();

    return 0;
}