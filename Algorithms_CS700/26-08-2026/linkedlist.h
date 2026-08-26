#pragma once
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool empty(Node* head) {
    return (head == NULL);
}

void push(Node*& head, int data) {
    Node* node = new Node();
    node->data = data;
    node->next = head;
    head = node;
}

void enqueue(Node*& head, Node*& tail, int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    
    if (empty(head)) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

int pop(Node*& head) {
    Node* junk = head;
    head = head->next;
    int val = junk->data;
    delete junk;
    return val;
}

int dequeue(Node*& head, Node*& tail) {
    Node* junk = head;
    head = head->next;
    int val = junk->data;
    delete junk;

    if (empty(head)) tail = head;

    return val;
}

void printLinkedList(Node* head) {
    if (empty(head)) return;
    cout << head->data;
    
    Node* temp = head->next;
    while (temp != NULL) {
        cout << " -> " << temp->data;
        temp = temp->next;
    }

    cout << endl;
}