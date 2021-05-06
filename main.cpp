#include <iostream>
#include <iomanip>
#include <queue>
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
int n;
int nr;
int h;
int d;
void CSCAN(int requests[]){
    cout << h ;
    queue<int> q;
    int v;
    int total_d=0;
    int maxr = -MAX;
    int minr = MAX;
    int maxrr;
    int minrr;
    int i=0;
    sort(requests,requests+nr,greater<int>());
    maxr = requests[0];
    while(1){
        v=requests[i];
        if(v<h)
            break;
        else maxrr = v;
        i++;
    }
    i=0;
    sort(requests,requests+nr);
    minr = requests[0];
    while(1){
        v = requests[i];
        if(v>h)
            break;
        else minrr = v;
        i++;
    }
    if(d==1){
        for(int i=0 ; i<nr ;i++){
            v = requests[i];
            if(v>=h)
               cout<<" -> " << v;
            else{
                q.push(v);
            }
        }
        while(!q.empty()){
            v= q.front();
            q.pop();
            cout << " -> " << v;
        }
        cout << endl;
        total_d = abs(h-maxr)+abs(minr-minrr)+abs(maxr-minr);
    }
    if(d==-1){
        sort(requests,requests+nr,greater<int>());
        for(int i=0 ; i<nr ;i++){
            v = requests[i];
            if(v<h)
               cout<<" -> " << v;
            else{
                q.push(v);
            }
        }
        while(!q.empty()){
            v= q.front();
            q.pop();
            cout << " -> " << v;

        }
        cout << endl;
        total_d = abs(h-minr)+abs(maxr-maxrr)+abs(maxr-minr);;
    }
    float avg = float(total_d)/float(nr);
    cout << "Total head movements = " << total_d << endl;
    cout << fixed << setprecision(5);
    cout << "Average head movement = " << avg << endl;

}
void SCAN(int requests[]){
    cout << h ;
    stack<int> s;
    queue<int> q;
    int v;
    int maxr = -MAX;
    int minr = MAX;
    int total_d;
    sort(requests,requests+nr);
    minr = requests[0];
    maxr = requests[nr-1];
    if(d==1){
        for(int i=0 ; i<nr ;i++){
            v = requests[i];
            if(v>=h)
               cout<<" -> " << v;
            else{
                s.push(v);
            }
        }
        while(!s.empty()){
            v= s.top();
            s.pop();
            cout << " -> " << v;
        }
        cout << endl;
        total_d = abs(h-maxr)+abs(maxr-minr);
    }
    stack<int> s2;
    if(d==-1){
        for(int i=0 ; i<nr ;i++){
            v = requests[i];
            if(v<h)
                s2.push(v);
            else
                q.push(v);
        }
        while(!s2.empty()){
            v= s2.top();
            s2.pop();
            cout << " -> " << v;
        }
        while(!q.empty()){
            v= q.front();
            q.pop();
            cout << " -> " << v;
        }
        cout << endl;
        total_d = abs(h-minr)+abs(maxr-minr);
    } //27 129 110 186 147 41 10 64 120
    float avg = float(total_d)/float(nr);
    cout << "Total head movements = " << total_d << endl;
    cout << fixed << setprecision(5);
    cout << "Average head movement = " << avg << endl;
}
void FIFO(int requests[]){
    int i = 0;
    int r, dist, total_d=0;
    cout << h ;
    while(i < nr){
        r = requests[i];
        d = abs(h-r);
        h = r;
        total_d+=d;
        cout << " -> " << h ;
        i++;
    }
    float avg = float(total_d)/float(nr);
    cout << endl;
    cout << "Total head movements = " << total_d << endl;
    cout << fixed << setprecision(5);
    cout << "Average head movement = " << avg << endl;

}
int main()
{
    int mechanism;
    cout << "Enter the size of the disk:";
    cin >> n;
    cout << "Enter number of requests:";
    cin >> nr;
    int requests[nr];
    cout << "Enter the requests:";
    for( int i = 0; i < nr ; i++)
        cin >> requests[i];
    cout << "Enter the head position:";
    cin >> h;
    cout << "Enter the head direction(1 for right -1 for left):";
    cin >> d;
    cout << "enter 1 for FIFO 2 for SCAN 3 for CSAN:";
    cin >> mechanism;
    switch(mechanism){
        case 1: FIFO(requests); break;
        case 2: SCAN(requests); break;
        case 3: CSCAN(requests); break;
    }
    return 0;
}
