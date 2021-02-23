#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void printWorld(){
    printf(" world!");
}


int main(int argc, char* argv[]){

    pid_t child_pid = fork();

    printf("%d\n", child_pid);

    if(child_pid == 0){
        printf("Hello");
        //raise(1);
    } else {
        //signal(1, printWorld);
    }

    return 0;
}

//Using signal the child could wait for the parent