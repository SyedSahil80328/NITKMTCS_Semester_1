#include "graph.h"
// #include "traversal.h"

int main() {
    Graph undirectedGraph(6, false);
    cout << "Undirected Graph:\n";
    undirectedGraph.addEdge(0, 1, 3);
    undirectedGraph.addEdge(0, 2, 2);
    undirectedGraph.addEdge(0, 3, 8);
    undirectedGraph.addEdge(1, 2, 6);
    undirectedGraph.addEdge(1, 4, 4);
    undirectedGraph.addEdge(2, 4, 4);
    undirectedGraph.addEdge(2, 3, 7);
    undirectedGraph.addEdge(4, 5, 9);
    undirectedGraph.addEdge(2, 5, 8);
    undirectedGraph.print();

    // cout << "Directed Graph:\n";
    // Graph directedGraph(6, true);
    // for (int i=0 ; i<5 ; i++) {
    //     for (int j=i+1 ; j<6 ; j++) {
    //         directedGraph.addEdge(i, j);
    //     }
    // }
    // directedGraph.print();

    // TraversalAlgorithms functionsUG(undirectedGraph);
    // TraversalAlgorithms functionsDG(directedGraph);

    // functionsUG.dfs(0);

    // int* result = functionsUG.getResult();
    // int* parent = functionsUG.getParent();

    // cout << "\nDFS of given undirected Graph: (parent[result[i]] -> result[i]):\n";

    // for (int i=0 ; i<undirectedGraph.getN() ; i++) {
    //     cout << parent[result[i]] << " -> " << result[i] << endl;
    // }
    // cout << endl;

    // functionsUG.bfs(0);

    // result = functionsUG.getResult();
    // parent = functionsUG.getParent();

    // cout << "\nBFS of given undirected Graph: (parent[result[i]] -> result[i]):\n";

    // for (int i=0 ; i<undirectedGraph.getN() ; i++) {
    //     cout << parent[result[i]] << " -> " << result[i] << endl;
    // }
    // cout << endl;

    return 0;
}