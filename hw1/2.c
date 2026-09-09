#include <stdio.h>

int main()
{
    int a[5] = {0, 1, 2, 3, 4};

    int *ptn = &a[0];

    for (int i = 0; i < 5; i++)
    {
        printf("value of a[%d]: %d\n", i, *(ptn + i));
    }

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
         *(ptn + i) += -4;
    }

    printf("modified array using pointer:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("value of a[%d]: %d\n", i, *(ptn + i));
    }

    printf("\n");
    printf("modified array using array name:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("value of a[%d]: %d\n", i, a[i]);
    }

    return 0;
}
