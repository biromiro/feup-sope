#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#define MAXLINE 20

int main(){
    int   n, fd[2];
    pid_t pid;
    char  line[MAXLINE];
    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe error\n");
        exit(1);
    } 
    
    if ( (pid = fork()) < 0) {
        fprintf(stderr, "fork error\n");
        exit(2);
    } else if (pid > 0) {
        /* parent */
        close(fd[1]); 
        /* closes emmiter side of the pipe  */
        n = read(fd[0], line, MAXLINE);
        char* st = malloc(sizeof(char) * n);
        memcpy(st, line, n);
        printf("Operating %s", st);
        free(st);
    } else {                      
        /* filho */
        close(fd[0]);
           
        /* closes receptor side of the pipe */

         write(fd[1], "Systems", 7);
        
    }
    exit(0);
}