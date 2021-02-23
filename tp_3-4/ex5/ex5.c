#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){

    pid_t child_pid, wpid;
    child_pid = fork();
    int * val;

    switch (child_pid) {
        case -1: perror ("fork"); exit (1);
        case 0: printf("Hello "); break;
        default: {
            while ((wpid = wait(val)) > 0);
            printf("world!");
        }
    }

    return 0;
}

//Using signal the child could wait for the parent