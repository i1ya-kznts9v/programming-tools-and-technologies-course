#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PAGE_SIZE_B 4 * 1024 // 4kb
#define SLEEP 1000 // 1msec
#define EVERY 1000 // 1k

void print_usage(const char* name) {
    printf("Usage: %s <size_mb> <read|write>\n", name);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    const size_t size_mb = strtoull(argv[1], NULL, 10);
    const char* mode = argv[2];
    if (size_mb <= 0 || (strcmp(mode, "read") != 0 && strcmp(mode, "write") != 0)) {
        print_usage(argv[0]);
        return 1;
    }

    const size_t size_b = (size_t) size_mb * 1024 * 1024;
    char* memory = (char*) malloc(size_b);
    if (memory == NULL) {
        printf("Allocation %zumb of memory was failed.\n", size_mb);
        return 1;
    }
    printf("Allocated %zumb of memory.\n", size_mb);

    size_t commits = 0;
    for (size_t i = 0; i < size_b; i += PAGE_SIZE_B) {
        if (strcmp(mode, "write") == 0) {
            memory[i] = 0;
        } else if (strcmp(mode, "read") == 0) {
            // Disable compiler optimizations for unused memory read
            volatile char value = memory[i];
            (void)value;
        }

        commits++;
        if (commits % EVERY == 0) {
            printf("Executing %s operation... %zumb/%zumb\n", mode, i / (1024 * 1024), size_mb);
            usleep(SLEEP);
        }
    }
    printf("Completed %s operation on %zumb of memory.\n", mode, size_mb);

    free(memory);
    return 0;
}
