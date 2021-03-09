#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void printHello(){
    printf("Hello!");
}

void ended(){
    printf("/nFinished!");
}

int main(int argc, char* argv[]){

    struct sigaction new, old;
    sigset_t smask;

    if (sigemptyset(&smask)==-1)	// block no signal
        perror ("sigsetfunctions");
    new.sa_handler = printHello;
    new.sa_mask = smask;
    new.sa_flags = 0;

    if(sigaction(SIGUSR1, &new, &old) == -1)
        perror ("sigaction");

    pid_t child_pid = fork();

    if((size_t) child_pid == 0){
        pause();
    } else {
        printf("World: ");
        kill(child_pid, SIGUSR1);
    }

    return 0;
}

//Using signal the child could wait for the parent