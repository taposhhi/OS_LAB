#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <sys/wait.h>

using namespace std;

sem_t mutex;

void print_lines() {
    pid_t pid = getpid();
    sem_wait(&mutex);
    cout << "Hello I am process no " << pid << endl;
    cout << "Hello I am process no " << pid << endl;
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
