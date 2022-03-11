class Solution {
public:
    bool dfs(int node,int cl,int col[],bool vis[],vector<vector<int>> &adj)
    {
        vis[node] = 1;
        col[node] = cl;
        for(auto &child : adj[node])
        {
            if(vis[child])
            {
                if(col[child] == col[node]) return false;
                continue;
            }
            if(!dfs(child,cl^1,col,vis,adj)) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int col[n+1]; bool vis[n+1];
        memset(col,-1,sizeof(col));
        memset(vis,false,sizeof(vis));
        vector<vector<int>> adj(n+1,vector<int>(0));
        for(auto &v : dislikes)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(!dfs(i,0,col,vis,adj)) return false;
        }
        return true;
    }
};