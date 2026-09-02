
#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    printf("Hello from the thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, task, NULL);
    printf("Hello from main!\n");
    pthread_join(thread, NULL);
    printf("Thread has finished.\n");
    return 0;
}
