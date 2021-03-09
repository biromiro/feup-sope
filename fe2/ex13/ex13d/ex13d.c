#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAXLINE 20

int main(){
    int   n, fd[2];
    pid_t pid;
    char  line[MAXLINE];
    
    if (mkfifo("np",0666) < 0){
        fprintf(stderr, "pipe error\n");
        exit(1);
    } 
    
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    } 

    if (pid > 0) {
        /* parent */

        int np;
        while ((np = open ("np", O_RDONLY)) < 0);          

        n = read(np, line, MAXLINE);
        char* st = malloc(sizeof(char) * n);
        memcpy(st, line, n);
        printf("Operating %s", st);
        free(st);
        close(np);
    } else {                      
        /* filho */
        int np;
        while ((np = open ("np", O_WRONLY)) < 0);

        write(np, "Systems", 7);
        close(np); 
    }
    exit(0);
}