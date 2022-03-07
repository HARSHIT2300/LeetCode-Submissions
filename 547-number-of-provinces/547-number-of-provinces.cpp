class Solution {
public:
    void dfs(int node,bool vis[],vector<vector<int>> &isConnected)
    {
        vis[node]=1;
        int n = isConnected.size();
        for(int i=0;i<n;i++)
        {   
            if(isConnected[node][i]== 0 || i== node || vis[i]) continue;
            dfs(i,vis,isConnected);
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            dfs(i,vis,isConnected);
            ans++;
        }
        return ans;
    }
};