#include "graph.h"
#include "traversal.h"

int main() {
    Graph undirectedGraph(6, false);
    cout << "Undirected Graph:\n";
    for (int i=0 ; i<5 ; i++) {
        for (int j=i+1 ; j<6 ; j++) {
            undirectedGraph.addEdge(i, j);
        }
    }
    undirectedGraph.print();

    cout << "Directed Graph:\n";
    Graph directedGraph(6, true);
    for (int i=0 ; i<5 ; i++) {
        for (int j=i+1 ; j<6 ; j++) {
            directedGraph.addEdge(i, j);
        }
    }
    directedGraph.print();

    TraversalAlgorithms functionsUG(undirectedGraph);
    TraversalAlgorithms functionsDG(directedGraph);

    functionsUG.dfs(0);

    int* result = functionsUG.getResult();
    int* parent = functionsUG.getParent();

    cout << "\nDFS of given undirected Graph: (parent[result[i]] -> result[i]):\n";

    for (int i=0 ; i<undirectedGraph.getN() ; i++) {
        cout << parent[result[i]] << " -> " << result[i] << endl;
    }
    cout << endl;

    functionsUG.bfs(0);

    result = functionsUG.getResult();
    parent = functionsUG.getParent();

    cout << "\nBFS of given undirected Graph: (parent[result[i]] -> result[i]):\n";

    for (int i=0 ; i<undirectedGraph.getN() ; i++) {
        cout << parent[result[i]] << " -> " << result[i] << endl;
    }
    cout << endl;

    return 0;
}