#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int child = fork();

    if (child == 0) {
        printf("Child: exiting now\n");
        exit(0);
    }
    
    wait(NULL);
    printf("Parent: child PID is %d, sleeping 30 seconds to check with htop\n", child);
    sleep(30);
    return 0;
}
