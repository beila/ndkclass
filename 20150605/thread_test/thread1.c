#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_func(void *arg) {
    int i;
    for(i = 0; i < 10; ++i) {
	printf("\t%s\n", p);
	sleep(1);
    }
    return 0;
}

void main() {
    pthread_t tid;
    if (pthread_create(&tid, 0, thread_func, "hello") != 0) {
	perror("pthread_create");
	return;
    }

    if (pthread_create(&tid, 0, thread_func, "pthread") != 0) {
	perror("pthread_create");
	return;
    }

    while(1) {
	printf(".\n");
	sleep(1);
    }
}
