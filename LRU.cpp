#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n,f,pf=0;

    cout<<"number of pages : ";
    cin>>n;

    vector<int> p(n);
    cout<<"pages : ";
    for(int i=0;i<n;i++) cin>>p[i];

    cout<<"frame : ";
    cin>>f;

    vector<int> frame(f,-1);

    for(int i=0;i<n;i++){
        bool hit=false;

        // check hit
        for(int j=0;j<f;j++){
            if(frame[j]==p[i]){
                hit=true;
                break;
            }
        }

        if(hit){
            for(int j=0;j<f;j++) cout<<"_ ";
        }
        else{
            pf++;

            int pos=-1;

            // check empty frame
            for(int j=0;j<f;j++){
                if(frame[j]==-1){
                    pos=j;
                    break;
                }
            }

            // LRU replacement
            if(pos==-1){
                int least=INT_MAX,idx=-1;

                for(int j=0;j<f;j++){
                    int k;

                    for(k=i-1;k>=0;k--){
                        if(frame[j]==p[k])
                            break;
                    }

                    if(k<least){
                        least=k;
                        idx=j;
                    }
                }

                pos=idx;
            }

            frame[pos]=p[i];

            // print frame
            for(int j=0;j<f;j++){
                if(frame[j]==-1) cout<<"* ";
                else cout<<frame[j]<<" ";
            }
        }

        cout<<endl;
    }

    cout<<"Total Page Fault: "<<pf;
}


/**
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
*/
