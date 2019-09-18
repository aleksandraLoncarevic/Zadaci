#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS     850

void *PrintHello(void *threadid)
{
   long taskid;
   sleep(1);
   taskid = *(long *)threadid;
   printf("Hello from thread %ld\n", taskid);
   pthread_exit(NULL);
}

void main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t=0;t<NUM_THREADS;t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *) &t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
