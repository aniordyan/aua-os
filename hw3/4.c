#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;

    int child1 = fork();
    if (child1 == 0) {
        exit(0);  
    }

    int child2 = fork();
    if (child2 == 0) {
        exit(1); 
    }

    waitpid(child1, &status, 0);
    printf("Child1 exit status: %d\n", WEXITSTATUS(status));
    if (WEXITSTATUS(status) == 0)
        printf("Child1 exited normally\n");
    else
        printf("Child1 exited with an error\n");

    waitpid(child2, &status, 0);
    printf("Child2 exit status: %d\n", WEXITSTATUS(status));
    if (WEXITSTATUS(status) == 0)
        printf("Child2 exited normally\n");
    else
        printf("Child2 exited with an error\n");

    return 0;
}
