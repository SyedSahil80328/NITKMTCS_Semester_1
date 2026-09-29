#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define OPERATIONS 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void enqueue(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    #pragma omp critical
    {
        if (tail == NULL) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }
}

int dequeue() {
    int value = -1;

    #pragma omp critical
    {
        if (tail != NULL) {
            Node *temp;

            if (head == tail) {
                value = tail->data;
                free(tail);
                head = NULL;
                tail = NULL;
            } else {
                temp = head;

                while (temp->next != tail) {
                    temp = temp->next;
                }

                value = tail->data;
                free(tail);
                tail = temp;
                tail->next = NULL;
            }
        }
    }

    return value;
}

int main() {
    double start = omp_get_wtime();

    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for (int i=0 ; i<OPERATIONS ; i++) {
                    enqueue(i);
                    printf("Produced: %d\n", i);
                }
            }

            #pragma omp section
            {
                int consumed = 0;

                while (consumed < OPERATIONS) {
                    int value = dequeue();

                    if (value != -1) {
                        printf("Consumed: %d\n", value);
                        consumed++;
                    }
                }
            }
        }
    }

    double elapsed = omp_get_wtime() - start;

    printf("\nProducer-Consumer using Linked List\n");
    printf("Operations: %d\n", OPERATIONS);
    printf("Time: %.9f seconds\n", elapsed);

    return 0;
}