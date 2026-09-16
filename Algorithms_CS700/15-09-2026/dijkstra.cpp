#include "../modules/graph.h"
#include "../modules/shortp.h"

int main () {
    Graph uwg(9, false, true);

    uwg.addEdge(0, 1, 5);
    uwg.addEdge(0, 2, 10);
    uwg.addEdge(1, 2, 2);
    uwg.addEdge(1, 4, 1);
    uwg.addEdge(2, 3, 8);
    uwg.addEdge(2, 5, 7);
    uwg.addEdge(3, 4, 4);
    uwg.addEdge(3, 5, 9);
    uwg.addEdge(4, 6, 12);
    uwg.addEdge(5, 6, 10);
    uwg.addEdge(5, 7, 19);
    uwg.addEdge(6, 7, 8);
    uwg.addEdge(6, 8, 24);
    uwg.addEdge(7, 8, 9);

    uwg.print();

    ShortestPath sp;
    sp.dijkstra(uwg, 0);
    return 0;
}