#pragma once
#include "linkedlist.h"

class Graph {
    Node** mainGraph;
    Node** endPoints;
    bool directed;
    int n;

    public:
        Graph(int n, bool directed) {
            this->n = n;
            this->directed = directed;

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

        void addEdge(int u, int v) {
            enqueue(this->mainGraph[u], this->endPoints[u], v);
            if (not directed) enqueue(this->mainGraph[v], this->endPoints[v], u);
        }

        void print() {
            for (int i=0 ; i<this->n ; i++) {
                cout << "Node " << i << ": ";
                printLinkedList(this->mainGraph[i]);
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