#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int child = fork();

    if (child == 0)
    {
        printf("Hello from child %d\n", getpid());
        exit(0);
    }

    printf("Hello from parent %d\n", getpid());

    return 0;
}
