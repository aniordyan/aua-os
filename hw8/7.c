#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char path1[256];
    char path2[256];
    char buffer1[1024];
    char buffer2[1024];
    int fd1;
    int fd2;
    ssize_t bytesRead1;
    ssize_t bytesRead2;
    off_t position = 0;

    printf("Enter first file path: ");
    scanf("%255s", path1);

    printf("Enter second file path: ");
    scanf("%255s", path2);

    fd1 = open(path1, O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening first file");
        return 1;
    }

    fd2 = open(path2, O_RDONLY);
    if (fd2 == -1) {
        perror("Error opening second file");
        close(fd1);
        return 1;
    }

    while (1) {
        bytesRead1 = read(fd1, buffer1, sizeof(buffer1));
        bytesRead2 = read(fd2, buffer2, sizeof(buffer2));

        if (bytesRead1 == -1 || bytesRead2 == -1) {
            perror("Error reading files");
            close(fd1);
            close(fd2);
            return 1;
        }

        ssize_t min = bytesRead1 < bytesRead2 ? bytesRead1 : bytesRead2;

        for (ssize_t i = 0; i < min; i++) {
            if (buffer1[i] != buffer2[i]) {
                printf("Files differ at byte %lld\n", (long long)(position + i));
                close(fd1);
                close(fd2);
                return 1;
            }
        }

        if (bytesRead1 != bytesRead2) {
            printf("Files differ at byte %lld\n",
                   (long long)(position + min));
            close(fd1);
            close(fd2);
            return 1;
        }

        if (bytesRead1 == 0) {
            break;
        }

        position += bytesRead1;
    }

    printf("Files are identical\n");

    if (close(fd1) == -1 || close(fd2) == -1) {
        perror("Error closing files");
        return 1;
    }

    return 0;
}

