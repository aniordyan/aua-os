#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *aligned_malloc(size_t size, size_t alignment) {
    //reject non 2^n alignment
    if (alignment == 0 || (alignment & (alignment - 1)) != 0) {
        return NULL;
    } 

    // extra space for alignment and for storing the original pointer
    void *original = malloc(size + alignment - 1 + sizeof(void *));

    if (original == NULL) {
        return NULL;
    }

    // store the original pointer
    uintptr_t start = (uintptr_t)original + sizeof(void *);

    size_t remainder = start % alignment;

    if (remainder != 0) {
        start += alignment - remainder;
    }

    void *aligned_ptr = (void *)start;

    ((void **)aligned_ptr)[-1] = original;

    return aligned_ptr;
}

void aligned_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    // get the original pointer
    void *original = ((void **)ptr)[-1];

    free(original);
}

int main() {
    size_t size = 100;
    size_t alignment = 64;

    void *ptr = aligned_malloc(size, alignment);

    if (ptr == NULL) {
        printf("Allocation failed.\n");
        return 1;
    }

    printf("Address: %p\n", ptr);

    if ((uintptr_t)ptr % alignment == 0) {
        printf("Memory is %zu-byte aligned.\n", alignment);
    }

    aligned_free(ptr);

    return 0;
}
