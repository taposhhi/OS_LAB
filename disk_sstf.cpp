#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cout << "Enter number of path : ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the paths : ";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Enter initial head position: ";
    cin >> head;

    int total = 0;

    cout << "\nQueue: " << head;

    while(!v.empty()) {
        int idx = 0;

        for(int i = 1; i < v.size(); i++) {
            if(abs(v[i] - head) < abs(v[idx] - head))
                idx = i;
        }

        total += abs(v[idx] - head);
        head = v[idx];

        cout << " -> " << head;
        v.erase(v.begin() + idx);
    }

    cout << "\nTotal Head Movement: " << total;
}
//98 183 37 122 14 124 65 67
