/*
Given an array of size n, generate and print all possible combinations of r elements in array.
*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& v) {
    for(int x: v) cout<<x<<" ";
    cout<<endl;
}

void solve(int i, int k, vector<int>& arr, vector<int>& v) {
    if(k==0) {
        print(v);
        return ;
    }
    if(i==arr.size()) return;
    v.push_back(arr[i]);
    solve(i+1, k-1, arr, v);
    v.pop_back();
    solve(i+1, k, arr, v);
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++) { int x; cin>>x; arr.push_back(x); }
    vector<int> v;
    solve(0,k,arr,v);
    return 0;
}
