#pragma once
#include "graph.h"
#include "linkedlist.h"

class TraversalAlgorithms {
    Graph& graph;
    int* parent;
    bool* visited;
    int* result;

    int nodes = 0;

    public:
        int* getResult() {
            return result;
        }

        int* getParent() {
            return parent;
        }

        TraversalAlgorithms(Graph& graph) : graph(graph) {
            parent = new int[graph.getN()];
            visited = new bool[graph.getN()];
            result = new int[graph.getN()];
        }

        void dfs(int start) {
            nodes = 0;
            for (int i=0 ; i<graph.getN() ; i++) {
                visited[i] = false;
            }

            dfs_sub(start);

            for (int i=0 ; i<graph.getN() ; i++) {
                if (not visited[i]) dfs_sub(i);
            }
        }

        void dfs_sub(int start) {
            Node* stack = NULL;
            parent[start] = -1;
            push(stack, start);

            while (not empty(stack)) {
                int node = pop(stack);
                if (visited[node]) continue;

                result[nodes++] = node;
                visited[node] = true;
                Node* temp = graph.getAdjacencyList(node);

                while (temp != NULL) {
                    int v = temp->data;
                    if (not visited[v]) {
                        parent[v] = node;
                        push(stack, v);
                    }

                    temp = temp->next;
                }
            }
        }

        void bfs(int start) {
            nodes = 0;
            for (int i=0 ; i<graph.getN() ; i++) {
                visited[i] = false;
            }

            bfs_sub(start);

            for (int i=0 ; i<graph.getN() ; i++) {
                if (not visited[i]) bfs_sub(i);
            }
        }

        void bfs_sub(int start) {
            Node* queue = NULL;
            Node* tail = NULL;

            visited[start] = true;
            parent[start] = -1;
            enqueue(queue, tail, start);

            while (not empty(queue)) {
                int node = dequeue(queue, tail);
                result[nodes++] = node;
                Node* temp = graph.getAdjacencyList(node);

                while (temp != NULL) {
                    int v = temp->data;
                    if (not visited[v]) {
                        visited[v] = true;
                        parent[v] = node;
                        enqueue(queue, tail, v);
                    }

                    temp = temp->next;
                }
            }
        }

        ~TraversalAlgorithms() {
            delete[] parent;
            delete[] visited;
            delete[] result;
        }

        void bfs() {}
};