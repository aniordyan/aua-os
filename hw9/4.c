#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* compute_square(void* arg) {
    int* num = (int*)arg;
    int result = (*num) * (*num);

    printf("Square of %d is %d\n", *num, result);

    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    pthread_t threads[5];

    int created = 0;
    int status = 0;

    for (int i = 0; i < 5; i++) {
        int err = pthread_create(&threads[i], NULL, compute_square, &arr[i]);

        if (err != 0) {
            fprintf(stderr, "Failed to create thread %d\n",i + 1);
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

