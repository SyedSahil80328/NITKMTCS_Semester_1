#include "../modules/detcycle.h"

int main () {
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

    cout << "Directed graph S6C5 (It's a blend of S6 and C5 graphs (0 is center node in star and nodes 1 to 5 is a cycle)):\n";
    dg.print();

    CycleDetectorD cd;
    if (cd.hasCycle(dg)) {
        cout << "S6C5 has a cycle.\n";
        cd.printCycle();
    } else {
        cout << "S6C5 has no cycles. It's a DAG!\n";
        cd.printTopologicalOrder();
    }

    Graph dg2(6, true, false);
    dg2.addEdge(1, 0);
    dg2.addEdge(2, 0);
    dg2.addEdge(3, 0);
    dg2.addEdge(4, 0);
    dg2.addEdge(5, 0);

    cout << "\nDirected graph S6:\n";
    dg.print();

    if (cd.hasCycle(dg2)) {
        cout << "S6 has a cycle.\n";
        cd.printCycle();
    } else {
        cout << "S6 has no cycles. It's a DAG!\n";
        cd.printTopologicalOrder();
    }
}