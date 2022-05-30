int calc(int i,int f,vector<int>&prices,vector<vector<int>>& dp)
{
    if(i >= prices.size())  return 0;
    if(dp[i][f] != -1) return dp[i][f];
    if(f)
    {
        dp[i][f] = max(calc(i+1,1,prices,dp),calc(i+2,0,prices,dp)  + prices[i]);
    }
    else
    {
        dp[i][f] = max( calc(i+1,0,prices,dp),calc(i+1,1,prices,dp) - prices[i]);
    }
    return dp[i][f];
}


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int n = prices.size();
        dp[n][0]  = 0;
        dp[n][1]  = 0;
        calc(0,0,prices,dp);
        return dp[0][0];
    }
};