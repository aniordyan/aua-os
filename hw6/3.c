#include <stdio.h>

struct struct1 {
    char a;
    int b;
    double c;
};

#pragma pack(1)

struct struct2 {
    char a;
    int b;
    double c;
};


#pragma pack(2)

struct struct3 {
    char a;
    int b;
    double c;
};



int main() {
    struct struct1 n;
    struct struct2 p;
    struct struct3 p2;

    printf("Normal struct size: %zu bytes\n", sizeof(n));
    printf("Address of char: %p\n", &n.a);
    printf("Address of int: %p\n", &n.b);
    printf("Address of double: %p\n", &n.c);
    printf("\n");
    printf("Packed struct size: %zu bytes\n", sizeof(p));
    printf("Address of char: %p\n", &p.a);
    printf("Address of int: %p\n", &p.b);
    printf("Address of double: %p\n", &p.c);

    printf("\n");
    printf("Packed p2 struct size: %zu bytes\n", sizeof(p2));
    printf("Address of char: %p\n", &p2.a);
    printf("Address of int: %p\n", &p2.b);
    printf("Address of double: %p\n", &p2.c);

    return 0;
}
