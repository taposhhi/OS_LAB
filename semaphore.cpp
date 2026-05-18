#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

sem_t mutex;

void print_lines() {
    pid_t pid = getpid();
    sem_wait(&mutex);
    printf("Hello I am process no %d\n", pid);
    printf("Hello I am process no %d\n", pid);
    sem_post(&mutex);
}

int main() {
    sem_init(&mutex, 1, 1);
    fork();
    fork();
    print_lines();
    wait(NULL);
    wait(NULL);
    sem_destroy(&mutex);
    return 0;
}
