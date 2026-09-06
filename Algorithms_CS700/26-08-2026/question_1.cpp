#include "../modules/detcycle.h"

int main () {
    Graph ug(4, false, false);
    cout << "Undirected Graph C4:\n";
    ug.addEdge(0, 1);
    ug.addEdge(0, 2);
    ug.addEdge(2, 3);
    ug.addEdge(1, 3);

    ug.print();
    
    CycleDetectorU cu(ug.getN());
    if (cu.hasCycle(ug)) {
        cout << "C4 has a cycle!\n";
    } else {
        cout << "C4 doesn't has a cycle!\n";
    }
}