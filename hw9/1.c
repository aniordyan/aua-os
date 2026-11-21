#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Hello from thread! Thread ID: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];
    int created = 0;
    int status = 0;

    for (int i = 0; i < 3; i++) {
        int err = pthread_create(&threads[i], NULL, thread_function, NULL);

        if (err != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i + 1);
            status = 1;
            break;
        }

        created++;
    }

    for (int i = 0; i < created; i++) {
        int err = pthread_join(threads[i], NULL);

        if (err != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i + 1);
            status = 1;
        }
    }

    if (status == 0) {
        printf("All threads finished!\n");
    }

    return status;
}

