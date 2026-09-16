#include "graph.h"
#include "heap.h"
#include <algorithm>
#include <climits>

class ShortestPath {
    private:
        int *dist;
        bool *relax;
    public:
        void dijkstra(Graph& graph, int source) {
            dist = new int[graph.getN()];
            relax = new bool[graph.getN()];
            Edge* edges = new Edge[graph.getEdgeCount()*2];

            for (int i=0 ; i<graph.getN() ; i++) {
                dist[i] = INT_MAX;
            }
            dist[source] = 0;

            Heap h(edges, 0);
            h.insert({source, source, 0});
            int relaxed = graph.getN();

            while (h.getSize() && relaxed > 0) {
                Edge curr = h.pop();
                int u = curr.vertexV;

                if (relax[u]) {
                    continue;
                }

                relax[u] = true;
                relaxed--;

                dist[u] = curr.weight;
                Node* temp = graph.getAdjacencyList(u);

                while (temp != NULL) {
                    int v = temp->data.vertex;
                    int newDist = dist[u] + temp->data.weight;
                    
                    if (!relax[v] && newDist < dist[v]) {
                        dist[v] = newDist;
                        h.insert({u, v, newDist});
                    }
                    temp = temp->next;
                }
            }

            for (int i=0 ; i<graph.getN() ; i++) {
                cout << dist[i] << " ";
            }
            cout << endl;

            delete[] dist;
            delete[] relax;
            delete[] edges;
        }
};