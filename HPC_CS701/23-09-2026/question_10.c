#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define OPERATIONS 100
#define PRODUCERS 2
#define CONSUMERS 2

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int produced = 0;
int consumed = 0;

omp_lock_t lock;

void enqueue(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;

    if (tail == NULL) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head = node;
    }
}

int dequeue() {
    int value = -1;

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

    return value;
}

void producer(int id) {
    while (1) {
        omp_set_lock(&lock);

        if (produced >= OPERATIONS) {
            omp_unset_lock(&lock);
            break;
        }

        int value = produced;
        produced++;

        enqueue(value);

        printf("Producer %d produced: %d\n", id, value);

        omp_unset_lock(&lock);
    }
}

void consumer(int id) {
    while (1) {
        omp_set_lock(&lock);

        if (consumed >= OPERATIONS) {
            omp_unset_lock(&lock);
            break;
        }

        int value = dequeue();

        if (value != -1) {
            consumed++;
            printf("Consumer %d consumed: %d\n", id, value);
        }

        omp_unset_lock(&lock);
    }
}

int main() {
    omp_init_lock(&lock);

    double start = omp_get_wtime();

    #pragma omp parallel num_threads(PRODUCERS + CONSUMERS)
    {
        int id = omp_get_thread_num();

        if (id < PRODUCERS) {
            producer(id);
        } else {
            consumer(id - PRODUCERS);
        }
    }

    double elapsed = omp_get_wtime() - start;

    printf("\nMultiple Producer-Consumer using Linked List\n");
    printf("Producers: %d\n", PRODUCERS);
    printf("Consumers: %d\n", CONSUMERS);
    printf("Operations: %d\n", OPERATIONS);
    printf("Time: %.9f seconds\n", elapsed);

    omp_destroy_lock(&lock);

    return 0;
}