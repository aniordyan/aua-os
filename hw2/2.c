#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
    }

    wait(NULL);

    pid2 = fork();

    if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
    }

    wait(NULL);

    printf("Parent process done\n");

    return 0;
}
