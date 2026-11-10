#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char source[256];
    char destination[256];
    char buffer[1024];
    ssize_t bytesRead;
    ssize_t bytesWritten;
    ssize_t totalBytes = 0;

    printf("Enter source file path: ");
    scanf("%255s", source);

    printf("Enter destination file path: ");
    scanf("%255s", destination);

    int src = open(source, O_RDONLY);
    if (src == -1) {
        perror("Error opening source file");
        return 1;
    }

    int dest = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("Error opening destination file");
        close(src);
        return 1;
    }

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        ssize_t alreadyWritten = 0;

        while (alreadyWritten < bytesRead) {
            bytesWritten = write(dest, buffer + alreadyWritten, bytesRead - alreadyWritten);

            if (bytesWritten <= 0) {
                perror("Error writing to destination file");
                close(src);
                close(dest);
                return 1;
            }

            alreadyWritten += bytesWritten;
        }

        totalBytes += bytesRead;
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
        close(src);
        close(dest);
        return 1;
    }

    if (close(src) == -1) {
        perror("Error closing source file");
        close(dest);
        return 1;
    }

    if (close(dest) == -1) {
        perror("Error closing destination file");
        return 1;
    }

    printf("Total bytes copied: %zd\n", totalBytes);

    return 0;
}

