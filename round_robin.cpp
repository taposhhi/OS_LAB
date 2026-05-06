#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    string name[n];
    int burst[n], remaining[n];

    cout << "Enter process name and burst time:\n";
    for(int i = 0; i < n; i++)
        {
            cin >> name[i] >> burst[i];
            remaining[i] = burst[i];
        }





    int quantum;
    cout << "Time quantum : ";
    cin >> quantum;

    int time = 0;
    int waiting[n];
    int turnaround[n];
    int completion[n];   //  new array



    cout << "\nGantt Chart:\n" << time;


    bool done = false;
    while(!done)
        {
            done = true;

            for(int i=0; i<n; i++)
                {
                    if(remaining[i] > 0)
                        {
                            done = false;

                            if(remaining[i] > quantum)
                                {
                                    remaining[i] -= quantum;
                                    time += quantum;
                                    cout << " " << name[i] << " " << time;
                                }
                            else
                                {
                                    time += remaining[i];
                                    remaining[i] = 0;

                                    completion[i] = time;   //  only store finish time

                                    cout << " " << name[i] << " " << time;
                                }
                        }
                }
        }

    //  calculate here (easy way)
    for(int i=0; i<n; i++)
        {
            turnaround[i] = completion[i];
            waiting[i] = turnaround[i] - burst[i];
        }


    double avg_wt=0;

    for(int i=0; i<n; i++)
        {

            avg_wt += waiting[i];

        }

    avg_wt /= n;

    cout << "\nAverage Waiting Time: " << avg_wt << "\n";


    return 0;
}
