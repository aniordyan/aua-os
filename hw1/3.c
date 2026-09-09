#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() 
{
    int a = 0, b = 67;

    printf("before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after swap:  a = %d, b = %d\n", a, b);

    return 0;
}
