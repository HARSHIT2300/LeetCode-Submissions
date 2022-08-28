class Solution {
public:
    int calc(int l,int r,vector<int>& values,vector<vector<int>> &dp)
    {
        if(l+1 == r)
            return dp[l][r] = 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        for(int i = l+1 ; i < r; i++)
        {
            ans = min(ans, (values[i]*values[l]*values[r]) + calc(l,i,values,dp) + calc(i,r,values,dp));
        }
        dp[l][r] = ans == INT_MAX ? 0 : ans;
        return dp[l][r];
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        calc(0,n-1,values,dp);
        return dp[0][n-1];
    }
};