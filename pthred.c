#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printMil(void *ptr) {
    int i = 0;
    while (i < 1000000000) {
        i++;
    }
    printf("Hello, World!\n");
    return ptr;
}

int main(int argc, char ** argv) {
    pthread_t thread1, thread2;
    int ret;

    ret = pthread_create(&thread1, NULL, printMil, NULL);
    ret = pthread_create(&thread2, NULL, printMil, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}