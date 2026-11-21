#include <stdio.h>
#include <pthread.h>

typedef struct {
    int* array;
    int start;
    int end;
    int thread_id;
} thread_data_t;

void* arr_sum(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;

    int sum = 0;

    for (int i = data->start; i < data->end; i++) {
        sum += data->array[i];
    }

    printf("Thread %d: Sum = %d\n", data->thread_id, sum);

    return NULL;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(array) / sizeof(array[0]);

    pthread_t thread_1, thread_2;

    thread_data_t data_1 = {array, 0, size / 2, 1};
    thread_data_t data_2 = {array, size / 2, size, 2};

    if (pthread_create(&thread_1, NULL, arr_sum, &data_1) != 0) {
        fprintf(stderr, "Failed to create thread 1\n");
        return 1;
    }

    if (pthread_create(&thread_2, NULL, arr_sum, &data_2) != 0) {
        fprintf(stderr, "Failed to create thread 2\n");
        pthread_join(thread_1, NULL);
        return 1;
    }

    int status = 0;

    if (pthread_join(thread_1, NULL) != 0) {
        fprintf(stderr, "Failed to join thread 1\n");
        status = 1;
    }

    if (pthread_join(thread_2, NULL) != 0) {
        fprintf(stderr, "Failed to join thread 2\n");
        status = 1;
    }

    if (status == 0) {
        printf("Both threads finished!\n");
    }

    return status;
}

