#include "heap.h"
#include "detcycle.h"

class MSTAlgorithms {
    void printMST(Edge* mst, int size) {
        int cost = 0;
        cout << "The Minimum Spanning tree is:\n";

        for (int i = 0; i < size; i++) {
            cout << mst[i].vertexU << ", " << mst[i].vertexV << ", " << mst[i].weight << '\n';
            cost += mst[i].weight;
        }

        cout << "\nThe total cost of the MST is " << cost << "\n";
    }

public:
    void kruskal(Graph& graph) {
        Edge* edges = new Edge[graph.getEdgeCount()];
        Edge* mst = new Edge[graph.getN() - 1];

        int edgeCount = 0;
        for (int i = 0; i < graph.getN(); i++) {
            for (Node* temp = graph.getAdjacencyList(i); temp != NULL; temp = temp->next) {
                if (i < temp->data.vertex)
                    edges[edgeCount++] = {i, temp->data.vertex, temp->data.weight};
            }
        }

        Heap h(edges, edgeCount);
        h.buildMinHeap();
        CycleDetectorU cu(graph.getN());

        int mstSize = 0;
        while (h.getSize() && mstSize < graph.getN() - 1) {
            Edge edge = h.pop();
            if (!cu.formsCycle(edge.vertexU, edge.vertexV))
                mst[mstSize++] = edge;
        }

        printMST(mst, mstSize);
        delete[] edges;
        delete[] mst;
    }

    void prims(Graph& graph, int start = 0) {
        Edge* edge = new Edge[graph.getEdgeCount()*2];
        Edge* mst = new Edge[graph.getN() - 1];
        bool* visited = new bool[graph.getN()]();

        Heap h(edge, 0);
        visited[start] = true;

        for (Node* temp = graph.getAdjacencyList(start); temp != NULL; temp = temp->next)
            h.insert({start, temp->data.vertex, temp->data.weight});

        int mstSize = 0;
        while (h.getSize() && mstSize < graph.getN() - 1) {
            Edge curr = h.pop();

            if (visited[curr.vertexV])
                continue;

            visited[curr.vertexV] = true;
            mst[mstSize++] = curr;

            for (Node* temp = graph.getAdjacencyList(curr.vertexV); temp != NULL; temp = temp->next)
                h.insert({curr.vertexV, temp->data.vertex, temp->data.weight});
        }

        printMST(mst, mstSize);
        delete[] edge;
        delete[] mst;
        delete[] visited;
    }
};