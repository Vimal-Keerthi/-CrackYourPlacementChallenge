/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*
        DP
        vector<int> dp(n,0);
        dp[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(prices[i],dp[i+1]);
        }
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<endl;

        int maxProfit=0;
        for(int i=0;i<n;i++){
            maxProfit = max(maxProfit, dp[i]-prices[i]);
        }
        return maxProfit;*/

        int pro=0;
        int minBuy=prices[0];
        for(int i=0;i<n;i++){
            pro = max(pro, prices[i]-minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        return pro;
    }
};

TC: O(n)
