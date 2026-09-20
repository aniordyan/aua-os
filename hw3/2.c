#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int status;

    int child1 = fork();
    if (child1 == 0) 
    {
        printf("Child 1: PID %d\n", getpid());
        exit(0);
    }

    int child2 = fork();
    if (child2 == 0) 
    {
        printf("Child 2: PID %d\n", getpid());
        exit(1);
    }

    printf("Parent: PID %d\n", getpid());

    waitpid(child2, &status, 0);   
    printf("Child 2 exit status: %d\n", WEXITSTATUS(status));

    wait(&status);               
    printf("Child 1 exit status: %d\n", WEXITSTATUS(status));

    return 0;
}
