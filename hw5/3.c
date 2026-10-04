#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr = malloc(10 * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", 10);

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int *new_arr = realloc(arr, 5 * sizeof(int));

    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr);
        return 1;
    }

    arr = new_arr;

    printf("Array after resizing: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
