#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {

  pid_t main = getpid();

  cout << "the main pid -> " << main << endl;

  int res = fork();

  if (res < 0) {
    // frok failed
    cout << "fork failed" << endl;
    exit(1);
  } else if (res == 0) {
    // fork success
    cout << "child proc : \t" << "  [child -> pid] : " << getpid()
         << "\t [parent -> pid] : " << main << endl;
  } else {
    pid_t wc = wait(NULL);
    cout << "parent proc : \t" << "  [parent -> pid] : " << getpid()
         << "\t [child -> pid] : " << wc << "\t [main -> pid] : " << main
         << endl;
  }

  return 0;
}
