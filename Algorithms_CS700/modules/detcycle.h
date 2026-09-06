#pragma once
#include "graph.h"

class CycleDetectorU {
    int *parent;
    int *rank;
    int nodes;

    public:
        CycleDetectorU(int nodes) {
            parent = new int[nodes];
            rank = new int[nodes];
            this->nodes = nodes;

            for (int i = 0; i < nodes; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = find(parent[u]);
        }

        bool unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) {
                return true;
            }

            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }

            return false;
        }

        bool hasCycle(Graph& graph) {
            for (int start=0 ; start<nodes ; start++) {
                Node* temp = graph.getAdjacencyList(start);
                while (temp != NULL) {
                    if (start < temp->data.vertex && unite(start, temp->data.vertex)) {
                        return true;
                    }
                    temp = temp->next;
                }
            }
            return false;
        }

        ~CycleDetectorU() {
            delete[] parent;
            delete[] rank;
        }
};


class CycleDetectorD {
    private:
        bool* visited;
        bool* instack;
        int* parent;
        int* order;

        int count;
        int cycleStart;
        int cycleEnd;

        bool DFS(Graph& graph, int start) {
            visited[start] = true;
            instack[start] = true;

            for (Node* temp = graph.getAdjacencyList(start);
                 temp != NULL;
                 temp = temp->next) {

                int v = temp->data.vertex;

                if (!visited[v]) {

                    parent[v] = start;

                    if (DFS(graph, v)) {
                        return true;
                    }

                }
                else if (instack[v]) {

                    // Back edge: start → v
                    cycleStart = v;
                    cycleEnd = start;

                    return true;
                }
            }

            instack[start] = false;

            // Finish time
            order[count++] = start;

            return false;
        }

    public:

        bool hasCycle(Graph& graphD) {
            int n = graphD.getN();

            visited = new bool[n];
            instack = new bool[n];
            parent = new int[n];
            order = new int[n];

            count = 0;
            cycleStart = -1;
            cycleEnd = -1;

            for (int i = 0; i < n; i++) {
                visited[i] = false;
                instack[i] = false;
                parent[i] = -1;
            }

            for (int i = 0; i < n; i++) {

                if (!visited[i]) {

                    if (DFS(graphD, i)) {
                        return true;
                    }
                }
            }

            return false;
        }

        void printCycle() {
            Node* stack = NULL;
            if (cycleStart == -1) {
                return;
            }

            int current = cycleEnd;
            push(stack, cycleStart);

            while (current != cycleStart) {
                push(stack, current);
                current = parent[current];
            }
            
            cout << "Cycle: " << cycleStart;
            while (!empty(stack)) {
                cout << " -> " << pop(stack).vertex;
            }
            cout << endl;
        }

        void printTopologicalOrder() {
            if (count == 0) {
                return;
            }

            cout << "Topological Order: ";

            for (int i = count - 1; i >= 0; i--) {
                cout << order[i] << " ";
            }

            cout << endl;
        }

        ~CycleDetectorD() {
            delete[] visited;
            delete[] instack;
            delete[] parent;
            delete[] order;
        }
};