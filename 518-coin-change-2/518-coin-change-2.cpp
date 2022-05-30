int calc(int n,int amt,vector<vector<int>> &dp,vector<int>&coins)
{
   // if(amt<0) return 0;
    if(dp[n][amt]!=-1) return dp[n][amt];
    if(amt == 0) return dp[n][amt] = 1;
    if(n == 0)return dp[n][amt] = 0;
    if(coins[n-1]<=amt)
        dp[n][amt] = calc(n-1,amt,dp,coins) + calc(n,amt-coins[n-1],dp,coins);
    else
        dp[n][amt] = calc(n-1,amt,dp,coins);
    return dp[n][amt];
}
// seems like an unbounded knapsack problem... lets try recursive appraoch first; as more intuitive 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp;
        vector<int> v(amount+1,-1);
        for(int i=0;i<=coins.size();i++)
        {
            dp.push_back(v);
        }
       calc(coins.size(),amount,dp,coins);
       return dp[coins.size()][amount]; 
    }
};