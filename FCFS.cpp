#include<bits/stdc++.h>
using namespace std;

int main()
{


    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    string process[n];
    int burst[n];
    int waiting[n];


    cout << "Enter process name and burst time: ";
    cout<<endl;
    for(int i = 0; i < n; i++)
        {
            cin >> process[i] >> burst[i];
        }


    waiting[0] = 0;
    for(int i = 1; i < n; i++)
        {
            waiting[i] = waiting[i-1] + burst[i-1];
        }


    int time = 0;
    cout << time << " ";

    for(int i = 0; i < n; i++)
        {
            cout << process[i] << " ";
            time += burst[i];
            cout << time << " ";
        }


    float total_wait = 0;
    for(int i = 0; i < n; i++)
        {
            total_wait += waiting[i];
        }

    float avg_wait = total_wait / n;

    cout << "\n\nAverage Waiting Time: " << avg_wait << endl;





    return 0;
}

