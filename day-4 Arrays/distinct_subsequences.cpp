/*
Distinct subsequences
*/

class Solution {
public:

    int f(int i, int j, string& s1, string& s2, int& m, int& n, vector<vector<int>>& dp){
        if(j==n) return 1;
        if(i==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        if(s1[i]==s2[j]) count += f(i+1, j+1, s1, s2, m, n, dp);
        count += f(i+1, j, s1, s2, m, n, dp);
        return dp[i][j] = count;
    }

    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        vector<vector<unsigned long>> dp(m+1, vector<unsigned long>(n+1, 0));
        // return f(0,0,s,t,m,n,dp);
        for(int i=0;i<=m;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++) dp[0][i]=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++) {
                dp[i][j]=0;
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
