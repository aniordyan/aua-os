#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the grades: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int highest = arr[0];
    int lowest = arr[0];    

    for (int i = 1; i < n; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }

    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);

    free(arr);

    return 0;
}
