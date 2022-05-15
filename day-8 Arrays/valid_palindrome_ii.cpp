/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

class Solution {
public:
    bool check( string s, int i, int j) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int p1=0, p2=s.size()-1;
        int count=1;
        while(p1<p2) {
            if(s[p1]==s[p2]) {p1++; p2--;}
            else {
                if(s[p1]!=s[p2] && count) {
                    bool res = check(s,p1, p2-1)||check(s,p1+1, p2);
                    return res;
                }
            }
        }
        return true;
    }
};
