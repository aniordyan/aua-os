#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char text[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buffer[27];
    ssize_t bytesRead;
    off_t size;

    fd = open("data.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, text, strlen(text)) != strlen(text)) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    fd = open("data.txt", O_RDWR);

    if (fd == -1) {
        perror("Error reopening file");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);

    if (size == -1) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    printf("Original file size: %lld bytes\n", (long long)size);

    if (ftruncate(fd, 10) == -1) {
        perror("Error truncating file");
        close(fd);
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);

    if (size == -1) {
        perror("Error getting new file size");
        close(fd);
        return 1;
    }

    printf("New file size: %lld bytes\n", (long long)size);

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error rewinding file");
        close(fd);
        return 1;
    }

    bytesRead = read(fd, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0';

    printf("Remaining content: %s\n", buffer);

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

