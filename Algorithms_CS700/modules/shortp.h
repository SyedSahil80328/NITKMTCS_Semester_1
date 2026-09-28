#pragma once

#include "graph.h"
#include "heap.h"
#include <algorithm>
#include <climits>

class ShortestPath {
private:
    int *dist;
    bool *relax;

    void printDistance(int source, int n) {
        cout << "Shortest path from source " << source << ".\n";

        for (int i = 0; i < n; i++) {
            cout << source << " -> " << i << ": " << dist[i] << ".\n";
        }

        cout << endl;
    }
public:
    void dijkstra(Graph& graph, int source) {
        int n = graph.getN();
        
        dist = new int[n];
        relax = new bool[n];
        Edge* edges = new Edge[graph.getEdgeCount()*2];

        for (int i=0 ; i<n ; i++) {
            dist[i] = INT_MAX;
            relax[i] = false;
        }
        dist[source] = 0;

        Heap h(edges, 0);
        h.insert({source, source, 0});
        int relaxed = n;

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

        printDistance(source, n);

        delete[] dist;
        delete[] relax;
        delete[] edges;
    }

    void bellmanFord(Graph& graph, int source) {
        int n = graph.getN();

        dist = new int[n];

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
        }

        dist[source] = 0;

        for (int i = 1; i < n; i++) {
            bool changed = false;

            for (int u = 0; u < n; u++) {
                Node* temp = graph.getAdjacencyList(u);

                while (temp != NULL) {
                    int v = temp->data.vertex;
                    int weight = temp->data.weight;

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {

                        dist[v] = dist[u] + weight;
                        changed = true;
                    }

                    temp = temp->next;
                }
            }

            if (!changed) {
                break;
            }
        }

        bool negativeCycle = false;

        for (int u = 0; u < n; u++) {
            Node* temp = graph.getAdjacencyList(u);

            while (temp != NULL) {
                int v = temp->data.vertex;
                int weight = temp->data.weight;

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    negativeCycle = true;
                    break;
                }

                temp = temp->next;
            }

            if (negativeCycle) {
                break;
            }
        }

        if (negativeCycle) {
            cout << "Graph contains a negative-weight cycle.\n";
        }
        else {
            printDistance(source, n);
        }

        delete[] dist;
    }
};