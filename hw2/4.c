#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0) {
        execl("/bin/grep", "grep", "վառ", "test.txt", NULL);
    } else {
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}
