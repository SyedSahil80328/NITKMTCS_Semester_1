#pragma once
#include "graph.h"

class TraversalAlgorithms {
    private:
        int* parent;
        bool* visited;
        int* result;
        int nodes = 0;

        void printRes() {
            for (int i=0 ; i<nodes ; i++) {
                cout << result[i] << " ";
            }
            cout << "\n";
        }

        void dfs_sub(Graph& graph, int start, int& count) {
            visited[start] = true;

            // Store discovery/visit order
            result[count++] = start;

            Node* temp = graph.getAdjacencyList(start);

            while (temp != NULL) {
                int v = temp->data.vertex;

                if (!visited[v]) {
                    parent[v] = start;
                    dfs_sub(graph, v, count);
                }

                temp = temp->next;
            }
        }

        void bfs_sub(Graph& graph, int start, int& count) {
            Node* queue = NULL;
            Node* tail = NULL;

            visited[start] = true;
            parent[start] = -1;
            enqueue(queue, tail, start);

            while (!empty(queue)) {
                int node = dequeue(queue, tail).vertex;

                // Store BFS visit order
                result[count++] = node;

                Node* temp = graph.getAdjacencyList(node);

                while (temp != NULL) {
                    int v = temp->data.vertex;

                    if (!visited[v]) {
                        visited[v] = true;
                        parent[v] = node;
                        enqueue(queue, tail, v);
                    }

                    temp = temp->next;
                }
            }
        }

        void initTrav(int n) {
            nodes = n;
            visited = new bool[nodes];
            parent = new int[nodes];
            result = new int[nodes];

            for (int i=0 ; i<nodes ; i++) {
                visited[i] = false;
                parent[i] = -1;
            }

            int count = 0;
        }

    public:
        void dfs(Graph& graph, int start) {
            initTrav(graph.getN());
            int count = 0;

            dfs_sub(graph, start, count);

            // In case graph is disconnected
            for (int i=0 ; i<nodes ; i++) {
                if (!visited[i]) {
                    dfs_sub(graph, i, count);
                }
            }
            printRes();
        }

        void bfs(Graph& graph, int start) {
            initTrav(graph.getN());
            int count = 0;
            bfs_sub(graph, start, count);

            // In case graph is disconnected
            for (int i=0 ; i<nodes ; i++) {
                if (!visited[i]) {
                    bfs_sub(graph, i, count);
                }
            }
            printRes();
        }

        ~TraversalAlgorithms() {
            delete[] parent;
            delete[] visited;
            delete[] result;
        }
};