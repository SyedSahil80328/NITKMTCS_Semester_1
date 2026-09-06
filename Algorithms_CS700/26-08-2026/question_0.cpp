#include "../modules/traversal.h"

int main () {
    Graph ug(4, false, false);
    cout << "Undirected Graph C4:\n";
    ug.addEdge(0, 1);
    ug.addEdge(0, 2);
    ug.addEdge(2, 3);
    ug.addEdge(1, 3);

    ug.print();
    
    TraversalAlgorithms ta;
    cout << "DFS traversal of C4: ";
    ta.dfs(ug, 0);
    cout << "BFS traversal of C4: ";
    ta.bfs(ug, 0);

    Graph dg(6, true, false);
    dg.addEdge(1, 0);
    dg.addEdge(2, 0);
    dg.addEdge(3, 0);
    dg.addEdge(4, 0);
    dg.addEdge(5, 0);
    dg.addEdge(1, 2);
    dg.addEdge(2, 3);
    dg.addEdge(3, 4);
    dg.addEdge(4, 5);
    dg.addEdge(5, 1);

    cout << "Directed graph S6C5 (It's a blend of star 6 and C5 graphs (0 is center node in star and nodes 1 to 5 is a cycle)):\n";
    dg.print();

    cout << "DFS traversal of S6C5: ";
    ta.dfs(dg, 0);
    cout << "BFS traversal of S6C5: ";
    ta.bfs(dg, 0);

}