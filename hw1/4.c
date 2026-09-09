#include <stdio.h>

int main() 
{
    int num = 34;
    int *ptr1;      
    int **ptr2;     

    ptr1 = &num;   
    ptr2 = &ptr1;   

    printf("Value of num: %d\n", num);               
    printf("Value pointed to by ptr1: %d\n", *ptr1);  
    printf("Value pointed to by ptr2: %d\n", **ptr2); 

    return 0;
}
