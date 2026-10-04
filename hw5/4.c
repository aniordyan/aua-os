#include <stdio.h>
#include <stdlib.h>

int main() {

    char **arr = malloc(3 * sizeof(char *));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = malloc(51 * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;

            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    printf("Enter 3 strings: ");

    for (int i = 0; i < 3; i++) {
        scanf("%50s", arr[i]);
    }


    char **new_arr = realloc(arr, 5 * sizeof(char *));

    if (new_arr == NULL) {
        printf("Memory reallocation failed.\n");

        for (int i = 0; i < 3; i++) {
            free(arr[i]);
        }

        free(arr);
        return 1;
    }

    arr = new_arr;

    for (int i = 3; i < 5; i++) {
        arr[i] = malloc(51 * sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }

            free(arr);
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (int i = 3; i < 5; i++) {
        scanf("%50s", arr[i]);
    }



    printf("All strings: ");

    for (int i = 0; i < 5; i++) {
        printf("%s ", arr[i]);
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}   

