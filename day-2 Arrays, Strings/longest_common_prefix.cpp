/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/


class Solution {
public:
    string lcp(string s1, string s2) {
        string res="";
        for(int i=0,j=0;i<s1.size() && j<s2.size();i++,j++){
            if(s1[i]==s2[j]) res+=s1[i];
            else break;
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res=strs[0];
        for(int i=1;i<strs.size();i++){
            res = lcp(res, strs[i]);
        }
        return res;
    }
};
