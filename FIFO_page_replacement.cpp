#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, f, pf = 0;

    cout<<"number of pages : ";
    cin >> n;

    vector<int> pages(n);
    cout<<"pages : ";
    for(int i = 0; i < n; i++) cin >> pages[i];

    cout<<"frame : ";
        cin >> f;

    vector<int> frame(f, -1); // -1 for Empty
    int idx = 0; // FIFO pointer

    for(int i = 0; i < n; i++)
        {
            bool hit = false;
            for(int j = 0; j < f; j++)
                {
                    if(frame[j] == pages[i])
                        {
                            hit = true;
                            break;
                        }
                }

            if(hit)
                {
                    for(int j = 0; j < f; j++) cout << "_ ";
                }
            else
                {
                    pf++;
                    frame[idx] = pages[i];
                    idx = (idx + 1) % f;

                    for(int j = 0; j < f; j++)
                        {
                            if(frame[j] == -1) cout << "* ";
                            else cout << frame[j] << " ";
                        }
                }
            cout << endl;
        }

    cout << "Total Page Fault: " << pf;
}


/**
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
