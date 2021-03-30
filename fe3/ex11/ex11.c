/* Testing access issues to shared variables
 * - Race conditions!
 * JMMC - Out.2001
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 20
#define MAX_ITER 1000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long count = 0, iter = 0;
void *thr_prod(void *);
void *thr_cons(void *);

int main(int argc, char *argv[]) {
    pthread_t *ptid;
    int nthreads;
    int i;

    setbuf(stdout, NULL);
    if (argc < 2) {
        printf("\nUsage: %s #threads\n", argv[0]);
        exit(1);
    }
    nthreads = atoi(argv[1]);
    ptid = (pthread_t *)malloc(nthreads * sizeof(pthread_t));
    if (ptid == NULL) {
        perror("malloc");
        exit(2);
    }
    for (i = 0; i < nthreads; i++) {
        if (i % 2 == 0) {
            if (pthread_create(&ptid[i], NULL, thr_prod, NULL) != 0) {
                perror("pthread_create");
                exit(3);
            }
        } else {
            if (pthread_create(&ptid[i], NULL, thr_cons, NULL) != 0) {
                perror("pthread_create");
                exit(3);
            }
        }
    }
    for (i = 0; i < nthreads; i++)
        pthread_join(ptid[i], NULL);

    printf("\nEND!\n");
    return 0;
}

void *thr_prod(void *arg) {
    while (iter < MAX_ITER) {
        pthread_mutex_lock(&mutex);
        iter++;
        count++;
        printf("%ld : produced - count = %ld\n", iter, count);
        pthread_mutex_unlock(&mutex);
    }
    printf("\nEND thread %lu!\n", (unsigned long)pthread_self());
    return (NULL);
}

void *thr_cons(void *arg) {
    while (iter < MAX_ITER) {
        pthread_mutex_lock(&mutex);
        iter++;
        count--;
        printf("%ld : consumed - count = %ld\n", iter, count);
        pthread_mutex_unlock(&mutex);
    }
    printf("\nEND thread %lu!\n", (unsigned long)pthread_self());
    return (NULL);
}
