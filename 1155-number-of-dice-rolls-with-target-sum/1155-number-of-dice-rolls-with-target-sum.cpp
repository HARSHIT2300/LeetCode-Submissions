#define mod 1000000007

int calc(int n,int& k,int target,vector<vector<int>> &dp)
{
   
   // if(target < 0) return 0;
    if(target == 0 ) return dp[n][target] = 0;
    if(n == 1)
    {
        if(target<=k) return dp[n][target] = 1;
        else return dp[n][target] = 0;
    } 
     if(dp[n][target] != -1 ) return dp[n][target];
    int sm=0;
    for(int i=1;i<=k;i++)
    {
        if(i<target)
            sm+=calc(n-1,k,target-i,dp);
        else 
            break;
        sm%=mod;
    }
    dp[n][target] = sm;
    return dp[n][target];
}


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        calc(n,k,target,dp);
        return dp[n][target];
    }
};