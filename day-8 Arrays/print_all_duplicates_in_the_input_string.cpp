/*
Write an efficient program to print all the duplicates and their counts in the input string
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    unordered_map<char, int> mp;
    cin>>str;
    for(int i=0;i<str.size();i++){
        mp[str[i]]++;
    }
    for(auto x: mp){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
