/*
Buy and sell stocks ii
*/

class Solution {
public:

    int f(int i, int prevStock, vector<int>& prices, vector<vector<int>>& dp) {
        if(i==prices.size()) return 0;
        if(dp[prevStock][i]!=-1) return dp[prevStock][i];
        int profit = 0;
        if(prevStock==1){
            profit = max( -prices[i]+f(i+1, 0, prices, dp), 0+f(i+1, 1, prices, dp));
        }
        else {
            profit = max( prices[i]+f(i+1, 1, prices, dp), 0+f(i+1, 0, prices, dp));
        }
        return dp[prevStock][i] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2,vector<int>(prices.size(), -1));
        return f(0, 1, prices, dp);
    }
};
