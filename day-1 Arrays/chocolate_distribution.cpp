/*
Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int x; cin>>x; arr.push_back(x);
    }
    if(n==0 || m==0) {cout<<0; return 0;}
    if(n<m) {cout<<-1; return 0;}
    sort(arr.begin(), arr.end());
    int min=INT_MAX;
    for (int i = 0; i + m - 1 < n; i++) {
        int x = arr[i + m - 1] - arr[i];
        if (x < min)
            min = x;
    }
    cout<<min;
    return 0;
}
