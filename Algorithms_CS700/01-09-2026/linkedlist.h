#pragma once
#include<iostream>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

bool empty(Node* head) {
    return (head == NULL);
}

void push(Node*& head, int vertex, int weight) {
    Node* node = new Node();
    node->vertex = vertex;
    node->weight = weight;
    node->next = head;
    head = node;
}

void enqueue(Node*& head, Node*& tail, int vertex, int weight) {
    Node* node = new Node();
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    
    if (empty(head)) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void printLinkedList(Node* head) {
    if (empty(head)) return;
    cout << "(" << head->vertex << ", " << head->weight << ")";
    
    Node* temp = head->next;
    while (temp != NULL) {
        cout << " -> " << "(" << temp->vertex << ", " << temp->weight << ")";
        temp = temp->next;
    }

    cout << endl;
}
