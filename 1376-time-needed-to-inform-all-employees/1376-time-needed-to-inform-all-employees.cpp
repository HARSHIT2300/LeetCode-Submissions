class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,bool vis[],vector<int> &informTime,int d,int &ans)
    {
        vis[node] = 1;
        ans = max(ans,d);
        for(auto curr : adj[node])
        {
            if(vis[curr]) continue;
            dfs(curr,adj,vis,informTime,d+informTime[curr],ans);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       
       bool vis[n];
        memset(vis,false,sizeof(vis));
        vector<vector<int>> adj(vector<vector<int>> (n,vector<int>(0)));
        for(int i=0;i<n;i++)
        {
            if(i==headID) continue;
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        int ans=0;
        dfs(headID,adj,vis,informTime,informTime[headID],ans);
        return ans;
    }
};