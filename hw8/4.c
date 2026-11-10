#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buffer[1024];
    char prefix[64];
    ssize_t bytesRead;
    off_t offset;

    fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter a log message: ");
    fflush(stdout);

    bytesRead = read(0, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) {
        perror("Error reading input");
        close(fd);
        return 1;
    }

    for (ssize_t i = 0; i < bytesRead; i++) {
        if (buffer[i] == '\n') {
            bytesRead = i;
            break;
        }
    }

    int prefixLen = snprintf(prefix, sizeof(prefix), "PID=%ld: ", (long)getpid());

    if (prefixLen < 0 || prefixLen >= (int)sizeof(prefix)) {
        fprintf(stderr, "Error creating prefix\n");
        close(fd);
        return 1;
    }

    if (write(fd, prefix, prefixLen) != prefixLen) {
        perror("Error writing prefix");
        close(fd);
        return 1;
    }

    if (write(fd, buffer, bytesRead) != bytesRead) {
        perror("Error writing message");
        close(fd);
        return 1;
    }

    if (write(fd, "\n", 1) != 1) {
        perror("Error writing newline");
        close(fd);
        return 1;
    }

    /*
    O_APPEND makes each write happen at the end of the file. After writing, the current file position moves forward.
    Therefore, SEEK_CUR returns an increasing offset.
    */

    offset = lseek(fd, 0, SEEK_CUR);

    if (offset == -1) {
        perror("Error getting file offset");
        close(fd);
        return 1;
    }

    printf("New file position: %lld bytes\n", (long long)offset);

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

