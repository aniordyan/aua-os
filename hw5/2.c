#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Array after calloc: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Enter %d integers: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Updated array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    double avg = (double)sum / n;
    printf("Average of the array: %.2f\n", avg);

    free(arr);

    return 0;
}
