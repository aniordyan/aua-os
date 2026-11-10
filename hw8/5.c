#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    off_t size;

    fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, "START", 5) != 5) {
        perror("Error writing START");
        close(fd);
        return 1;
    }

    if (lseek(fd, 1024 * 1024, SEEK_CUR) == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }

    if (write(fd, "END", 3) != 3) {
        perror("Error writing END");
        close(fd);
        return 1;
    }


    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    fd = open("sparse.bin", O_RDONLY);

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

    printf("Apparent file size: %lld bytes\n", (long long)size);

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}

/*
[from report] ...reported by du is much smaller because the skipped region is a sparse hole, and the operating system does not need to store all those empty bytes physically on disk...
*/
