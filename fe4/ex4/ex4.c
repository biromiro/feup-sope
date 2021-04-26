#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    long counter = 0;

    void* new_pointer[1000000];

    do {
        printf("malloc ->  %ld\n", counter);
        new_pointer[counter] = malloc(200000 * 1024);
        if (new_pointer[counter] == NULL) break;
        char* current = (char*)new_pointer[counter++];
        *current = 'a';
    } while (new_pointer[counter - 1] != NULL);

    printf("REJECTED MALLOC!");

    while (counter >= 0) {
        printf("free ->  %lu\n", counter);
        free(new_pointer[counter--]);
    }

    return 0;
}