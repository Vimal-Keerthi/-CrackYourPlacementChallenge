/*
Generate Parentheses
*/

class Solution {
public:
    void f(int op_c, int clo_c, int n, string s, vector<string>& v) {
        if(op_c==n && clo_c==n) {v.push_back(s); return ; }
        if(op_c < n) f(op_c+1, clo_c, n, s+'(', v);
        if(clo_c < op_c) f(op_c, clo_c+1, n, s+')', v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        f(0,0,n,"",v);
        return v;
    }
};
