#pragma once
#include "linkedlist.h"

class Graph {
    Node** mainGraph;
    Node** endPoints;
    bool directed;
    bool weighted;
    int edges = 0;
    int n;

    public:
        Graph(int n, bool directed, bool weighted) {
            this->n = n;
            this->directed = directed;
            this->weighted = weighted;

            this->mainGraph = new Node*[this->n];
            this->endPoints = new Node*[this->n];

            for (int i=0 ; i<this->n ; i++) {
                this->mainGraph[i] = NULL;
                this->endPoints[i] = NULL;
            }
        }

        int getN() {
            return this->n;
        }

        Node* getAdjacencyList(int node) {
            return mainGraph[node];
        }

        int getEdgeCount() {
            return edges;
        }

        void addEdge(int u, int v) {
            enqueue(this->mainGraph[u], this->endPoints[u], v);
            if (!directed) {
                enqueue(this->mainGraph[v], this->endPoints[v], u);
            }
            edges++;
        }

        void addEdge(int u, int v, int w) {
            enqueue(this->mainGraph[u], this->endPoints[u], v, w);
            if (!directed) {
                enqueue(this->mainGraph[v], this->endPoints[v], u, w);
            }
            edges++;
        }

        void print() {
            for (int i=0 ; i<this->n ; i++) {
                cout << "Node " << i << ": ";
                printLinkedList(this->mainGraph[i], weighted);
                cout << endl;
            }
            cout << endl;
        }

        ~Graph() {
            for (int i = 0; i < n; i++) {
                Node* temp = this->mainGraph[i];

                while (temp != NULL) {
                    Node* next = temp->next;
                    delete temp;
                    temp = next;
                }
            }

            delete[] this->mainGraph;
            delete[] this->endPoints;
        }
};