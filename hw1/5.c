#include <stdio.h>

int main() 
{
    char str[] = "Hello";
    char *ptr = str;

    printf("string using pointer: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    ptr = str;
    int count = 0;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    printf("number of characters: %d\n", count);

    return 0;
}
