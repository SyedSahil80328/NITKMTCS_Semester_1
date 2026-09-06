#pragma once
#include<iostream>
using namespace std;

struct Data {
    int vertex;
    int weight;
};

struct Node {
    Data data;
    Node* next;
};

bool empty(Node* head) {
    return (head == NULL);
}

void push(Node*& head, int vertex, int weight = 0) {
    Node* node = new Node();
    node->data.vertex = vertex;
    node->data.weight = weight;
    node->next = head;
    head = node;
}

void enqueue(Node*& head, Node*& tail, int vertex, int weight = 0) {
    Node* node = new Node();
    node->data.vertex = vertex;
    node->data.weight = weight;
    node->next = NULL;
    
    if (empty(head)) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

Data pop(Node*& head) {
    Node* junk = head;
    head = head->next;
    Data val = junk->data;
    delete junk;
    return val;
}

Data dequeue(Node*& head, Node*& tail) {
    Node* junk = head;
    head = head->next;
    Data val = junk->data;
    delete junk;

    if (empty(head)) tail = head;

    return val;
}

void printLinkedList(Node* head, bool weighted) {
    if (empty(head)) return;
    if (weighted) {
        cout << "(" << head->data.vertex << ", " << head->data.weight << ")";
    
        Node* temp = head->next;
        while (temp != NULL) {
            cout << " -> (" << temp->data.vertex << ", " << temp->data.weight << ")";
            temp = temp->next;
        }
    } else {
        cout << head->data.vertex;
        
        Node* temp = head->next;
        while (temp != NULL) {
            cout << " -> " << temp->data.vertex;
            temp = temp->next;
        }
    }
}