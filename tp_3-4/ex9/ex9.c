/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 3 //thread max depends of the machine the program is running

void *rot(void *a) {
	printf("\n\t In thread PID: %d ; TID: %lu. Thread number %d.", getpid(), (unsigned long) pthread_self(), *(int*)a);
    *(int *) a *= *(int *) a;
    sleep(3);
	pthread_exit(a);	// no termination code
	}

int main() {
	int i;	// thread counter
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers


setbuf (stdout, NULL);	// only for debugging
printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long) pthread_self());

// new threads creation
for(i=0; i<NTHREADS; i++) {
    int* creationNumber = malloc(sizeof(int));
    *creationNumber = i;
	if (pthread_create(&ids[i], NULL, rot, creationNumber) != 0)
		exit(-1);	// here, we decided to end process
	else
		printf("\nNew thread %d ; TID: %lu.", i, (unsigned long) ids[i]);
	}
// wait for finishing of created threads
for(i=0; i<NTHREADS; i++) {
    void* returnValue;
	pthread_join(ids[i], &returnValue);	// Note: threads give no termination code
	printf("\nTermination of thread %d: %lu. Returned %d.", i, (unsigned long)ids[i], *(int*) returnValue);
	}

printf("\n");
pthread_exit(NULL);	// here, not really necessary...
return 0;	// will not run this!
}
