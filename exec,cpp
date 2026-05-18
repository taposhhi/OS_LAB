#include <bits/stdc++.h>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {

  pid_t main_proc = getpid();

  pid_t res = fork();

  if (res < 0) {
    // fork failed
    cout << "fork failed" << endl;
    exit(1);
  } else if (res == 0) {
    // fork success
    cout << "child proc: PID -> " << getpid() << endl;

    char *args[] = {(char *)"./test.out", nullptr};

    execvp(args[0], args);

    cout << "this will not print" << endl;
  } else {
    pid_t wait_c = wait(NULL);
    cout << "parent proc : PID -> " << getpid() << "\t| main proc : PID -> "
         << main_proc << "\t| child proc: PID -> " << wait_c << endl;
  }

  return 0;
}
