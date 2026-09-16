#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fork1, fork2, fork3;

    fork1 = fork();

    fork2 = fork();

    fork3 = fork();


    printf("PID = %d, PPID = %d\n", getpid(), getppid());

    return 0;
}
