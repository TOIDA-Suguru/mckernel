#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/utsname.h>
#include <memory.h>
#include <sys/mman.h>
#include <sched.h>

#define NUM_THREADS 5

void *thread_fn_nop(void *arg)
{
	sleep(10);
}
void *thread_fn_dump(void *arg)
{
	int *ptr = NULL;

	*ptr = 0xdead;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	int i, j;
	int rets[NUM_THREADS];

	printf("SEGV in sub thread!!\n");

    /* Create threads */
	for (i = 0; i < NUM_THREADS; i++) {
		if (i == NUM_THREADS - 1) {
			/* SEGV thread */
			rets[i] = pthread_create(&threads[i], NULL,
					thread_fn_dump, NULL);
		} else {
			rets[i] = pthread_create(&threads[i], NULL,
					thread_fn_nop, NULL);
		}

		if (rets[i] != 0) {
			printf("pthread_create: %d\n", rets[i]);
		}
	}

	printf("pthread_create done!! Let's join!!!!\n");

	for (j = 0; j < NUM_THREADS; j++) {
		pthread_join(threads[j], NULL);
	}

	printf("All threads are done.\n");
	exit(0);
}

