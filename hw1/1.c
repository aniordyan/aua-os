#include <stdio.h>

int main()
{
    int a = 34;
    int *b = &a;

    printf("address of the integer variable (variable): %p\n", &a);
    printf("address of the integer variable (pointer): %p\n", b);

    *b = 43;
    printf("modified value of the integer (pointer): %d\n", *b);

    return 0;
}
