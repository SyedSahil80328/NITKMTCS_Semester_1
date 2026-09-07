#include "../modules/graph.h"
#include "../modules/sptree.h"

int main() {
    cout << "Sample Unweighted Graph: \n";
    Graph ug(6, false, true);
    ug.addEdge(0, 1, 3);
    ug.addEdge(0, 2, 2);
    ug.addEdge(0, 3, 8);
    ug.addEdge(1, 2, 6);
    ug.addEdge(1, 4, 4);
    ug.addEdge(2, 4, 4);
    ug.addEdge(2, 3, 7);
    ug.addEdge(4, 5, 9);
    ug.addEdge(2, 5, 8);
    ug.print();

    MSTAlgorithms mst;

    cout << "Exploring across all vertices present here.\n";
    for (int i=0 ; i<ug.getN() ; i++) {
        cout << "\nVertex " << i << ":\n";
        mst.prims(ug, i);
    }
}