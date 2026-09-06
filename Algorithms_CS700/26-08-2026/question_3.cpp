#include "../modules/graph.h"

class Bipartite {
    private:
        int* colors;
        bool* visited;

        bool dfs(Graph& graph, int start) {
            visited[start] = true;

            Node* temp = graph.getAdjacencyList(start);
            while (temp != NULL)
            {
                int v = temp->data.vertex;
                if (colors[v] == -1) {
                    colors[v] = 1 - colors[start];
                    if (!dfs(graph, v)) {
                        return false;
                    }
                } else if (colors[v] == colors[start]) {
                    return false;
                }
                temp = temp->next;
            }
            
            return true;
        }
    public:
        bool checkBipartite(Graph& graph) {
            colors = new int[graph.getN()];
            visited = new bool[graph.getN()];

            for (int i=0 ; i<graph.getN() ; i++) {
                colors[i] = -1;
                visited[i] = false;
            }

            for (int i=0 ; i<graph.getN() ; i++) {
                if (!visited[i]) {
                    colors[i] = 0;
                    if (!dfs(graph, i)) {
                        return false;
                    }
                }
            }

            return true;
        }
};

int main() {
    Graph ug(4, false, false);
    cout << "Undirected Graph C4:\n";
    ug.addEdge(0, 1);
    ug.addEdge(0, 2);
    ug.addEdge(2, 3);
    ug.addEdge(1, 3);

    ug.print();

    Bipartite bp;
    if (bp.checkBipartite(ug)) {
        cout << "C4 is bi-partite!\n";
    } else {
        cout << "C4 is not bi-partite!\n";
    }

    cout << "\nUndirected Graph K4:\n";
    ug.addEdge(0, 3);
    ug.addEdge(1, 2);

    ug.print();

    if (bp.checkBipartite(ug)) {
        cout << "K4 is bi-partite!\n";
    } else {
        cout << "K4 is not bi-partite!\n";
    }
}