#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];
    char ch;
    int line = 1;
    off_t position;
    ssize_t bytesRead;

    fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 1; i <= 10; i++) {
        char num[10];
        int len = snprintf(num, sizeof(num), "%d\n", i);

        if (write(fd, num, len) != len) {
            perror("Error writing numbers");
            close(fd);
            return 1;
        }
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    fd = open("numbers.txt", O_RDWR);

    if (fd == -1) {
        perror("Error reopening file");
        return 1;
    }

    while (line < 4) {
        bytesRead = read(fd, &ch, 1);

        if (bytesRead != 1) {
            fprintf(stderr, "Error finding line 4\n");
            close(fd);
            return 1;
        }

        if (ch == '\n') {
            line++;
        }
    }

    position = lseek(fd, 0, SEEK_CUR);

    if (position == -1) {
        perror("Error getting position");
        close(fd);
        return 1;
    }

    while ((bytesRead = read(fd, &ch, 1)) == 1) {
        if (ch == '\n') {
            break;
        }
    }

    if (bytesRead != 1) {
        perror("Error reading line 4");
        close(fd);
        return 1;
    }

    bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("Error reading remainder");
        close(fd);
        return 1;
    }

    if (lseek(fd, position, SEEK_SET) == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }

    if (write(fd, "100\n", 4) != 4) {
        perror("Error writing 100");
        close(fd);
        return 1;
    }

    if (write(fd, buffer, bytesRead) != bytesRead) {
        perror("Error writing remainder");
        close(fd);
        return 1;
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error rewinding file");
        close(fd);
        return 1;
    }

    printf("Final file content:\n");

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(1, buffer, bytesRead) != bytesRead) {
            perror("Error printing content");
            close(fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading final content");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

