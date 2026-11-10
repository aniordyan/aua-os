#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char path[256];
    char ch;
    int fd;
    off_t size;

    printf("Enter file path: ");
    scanf("%255s", path);

    fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);

    if (size == -1) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    for (off_t i = size; i > 0; i--) {

        if (lseek(fd, i - 1, SEEK_SET) == -1) {
            perror("Error using lseek");
            close(fd);
            return 1;
        }

        if (read(fd, &ch, 1) != 1) {
            perror("Error reading file");
            close(fd);
            return 1;
        }

        if (write(1, &ch, 1) != 1) {
            perror("Error writing to stdout");
            close(fd);
            return 1;
        }
    }

    if (write(1, "\n", 1) != 1) {
        perror("Error writing newline");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

