/*
*	EXEC: 1st example of typical usage!
*
* Note:	execve is the syscal!
*	execv, execvp, execvpe, execl, execlp, execle are library functions.
*
* Exercise:
* 	change this code to show that USER was changed after the exec.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

// preparation for execve:
char *cmdline[] = {"sleep", "30", (void *)0};
char *cmdline1[] = {};
char *newenviron[] = {"USER=Linus", NULL};

int main()
{
	pid_t id, val;
	int ret;
	setbuf(stdout, NULL); // to make sure printf() have no buffer so, nodelay!

	printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

	id = fork();
	switch (id)
	{
	case -1:
		perror("fork()");
		exit(1);
	case 0: // child
		printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));
		printf("\nChild: check that following exec was succeful with: \"ps x | grep sleep\"\n");
		int fd;
		if ((fd = open("ex2c.out", O_RDONLY)) == -1)
			return 1;
		return fexecve(fd, cmdline1, newenviron);
	default:
		printf("\nParent still: %d. USER=%s", getpid(), getenv("USER"));
		wait(&ret);
		printf("Return code: %d", WEXITSTATUS(ret));
	}
	return 0;
}
