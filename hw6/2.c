#include <stdio.h>

struct struct1 {
    char a;
    int b;
    double c;
};

struct struct2 {
    double c;
    int b;
    char a;
};

int main() {
    struct struct1 s1;
    struct struct2 s2;

    printf("First struct size: %zu bytes\n", sizeof(s1));
    printf("Address of char: %p\n", &s1.a);
    printf("Address of int: %p\n", &s1.b);
    printf("Address of double: %p\n", &s1.c);
    printf("\n");
    printf("Second struct size: %zu bytes\n", sizeof(s2));
    printf("Address of double: %p\n", &s2.c);
    printf("Address of int: %p\n", &s2.b);
    printf("Address of char: %p\n", &s2.a);

    return 0;
}
