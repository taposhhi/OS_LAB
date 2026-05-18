
#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

int main() {

  // the proc id of the main proc

  pid_t main_id = getpid();
  cout << "the pid of main proc: " << main_id << endl;

  // fork will return 0 if the child proc is created successfully
  //  fork will return -1 in case of errori ; fork failed

  pid_t res = fork();

  if (res == 0) {
    // inside the child proc
    cout << "child proc :" << "\t [child -> pid ] : " << getpid()
         << "\t [ parent -> pid ] : " << main_id << endl;
  } else if (res < 0) {
    // fork failed
    cout << "folk failed" << endl;
  } else {
    cout << "parent proc : " << "\t [ parent -> pid ] : " << getpid() << endl;
  }

  return 0;
}

