#include <stdio.h>
#include <stdlib.h>

void func1() 
{
    printf("func1 called\n");
}

void func2() 
{
    printf("func2 called\n");
}

int quit() 
{
    exit(0);
}

int main() 
{
    atexit(func1);
    //exit(0);
    atexit(func2);
    printf("Program running\n");
    
    exit(0);

    //quit();

    return 0;
}


