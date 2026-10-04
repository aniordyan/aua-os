#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);

    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size;

    if (old_size < new_size) {
        copy_size = old_size;
    } else {
        copy_size = new_size;
    }

    memcpy(new_ptr, ptr, copy_size);

    free(ptr);

    return new_ptr;
}

int main() {
    int *arr = malloc(5 * sizeof(int));

    if (arr == NULL) {
        return 1;
    }

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    printf("\n");

    int *temp = my_realloc(arr, 5 * sizeof(int), 10 * sizeof(int));

    if (temp == NULL) {
        free(arr);
        return 1;
    }

    arr = temp;

    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }

    printf("Resized array: ");

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}
