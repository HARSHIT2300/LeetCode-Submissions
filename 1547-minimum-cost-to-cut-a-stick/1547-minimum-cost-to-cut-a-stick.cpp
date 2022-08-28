class Solution {
public:
    int calc(int l,int r,bool vis[],vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(l+1 == r){dp[l][r] = 0; return dp[l][r] = 0;}
        if(dp[l][r] != -1)return dp[l][r];
        int ans = INT_MAX;
        for(int i=l+1;i<r;i++)
        {
         //   if(vis[i]) continue;
            vis[i] = 1;
            ans = min(ans, cuts[r] - cuts[l] + calc(l,i,vis,cuts,dp) + calc(i,r,vis,cuts,dp));
         //   vis[i] = 0;
        }
        dp[l][r] = ans == INT_MAX ? 0 : ans;
        return dp[l][r];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> cuts1(1,0);
        for(auto &el : cuts)
            cuts1.push_back(el);
        cuts1.push_back(n);
        bool vis[cuts1.size()];
        memset(vis,false,sizeof(vis));
        vector<vector<int>> dp(104,vector<int>(104,-1));
        calc(0,cuts1.size()-1,vis,cuts1,dp);
        return dp[0][cuts1.size()-1];
    }
};