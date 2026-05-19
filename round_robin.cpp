#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, quantum;

    cout << "Number of Process: ";
    cin >> n;

    vector<int> burst(n), remaining(n), waiting(n), turnaround(n);

    for (int i = 0; i < n; i++) {
        cout << "Burst time of P" << i + 1 << ": ";
        cin >> burst[i];
        remaining[i] = burst[i];
    }

    cout << "Time Quantum: ";
    cin >> quantum;

    int time = 0;
    bool finished=false;

    cout << "\nGantt Chart:\n";
    cout << time;

    while (!finished) {
        finished = true;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                finished = false;

                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    remaining[i] = 0;

                    turnaround[i] = time;
                    waiting[i] = turnaround[i] - burst[i];
                }

                cout << " P" << i + 1 << " " << time;
            }
        }

    }

    double avgWT = 0;


    for (int i = 0; i < n; i++) {

        avgWT += waiting[i];
    }

    cout << "\nAverage Waiting Time: " << avgWT / n << endl;

    return 0;
}
