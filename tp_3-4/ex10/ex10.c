/*
*	Example of threads in action
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define NTHREADS 2 //thread max depends of the machine the program is running

typedef struct{
	int argc;
	char** argv;
	bool done;
} thread_string_output;

typedef struct{
	int thread_number;
	thread_string_output* s;
} thread_info;

void *rot(void *a) {
	thread_info val = *(thread_info*)a;
	if(val.thread_number == 0){
		if(val.s->argc > 1)
			printf("%s ", val.s->argv[1]);
		val.s->done = true;
	}else{
		while(!(val.s->done));
		if(val.s->argc > 2){
			for(int i = 2; i < val.s->argc; i++) printf("%s ", val.s->argv[i]);
		}
	}
	pthread_exit(NULL);	// no termination code
}

int main(int argc, char* argv[]) {
	int i;	// thread counter
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers


	setbuf (stdout, NULL);	// only for debugging

	thread_string_output* values = malloc(sizeof(thread_string_output));
	values->argc = argc;
	(values->argv) = argv;
	values->done = false;

	// new threads creation
	for(i=0; i<NTHREADS; i++) {

		thread_info* val = malloc(sizeof(thread_info));
		val->thread_number = i;
		val->s = values;
		if (pthread_create(&ids[i], NULL, rot, val) != 0)
			exit(-1);	// here, we decided to end process
		}
	// wait for finishing of created threads
	for(i=0; i<NTHREADS; i++) {
		void* returnValue;
		pthread_join(ids[i], &returnValue);	// Note: threads give no termination code
	}

	pthread_exit(NULL);	// here, not really necessary...
	return 0;	// will not run this!
}
