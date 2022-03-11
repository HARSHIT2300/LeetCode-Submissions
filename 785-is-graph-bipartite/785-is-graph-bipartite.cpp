class Solution {
public:
    bool dfs(int node,int cl,int col[],bool vis[],vector<vector<int>>& graph)
    {
        vis[node] =1;
        col[node] = cl;
        for(auto &child : graph[node])
        {
            if(vis[child])
            {
                if(col[child] == col[node]) return false;
                continue;
            }
            if(!dfs(child,cl^1,col,vis,graph)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        bool vis[n];
        int col[n];
         memset(col,-1,sizeof(col));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            if(!dfs(i,0,col,vis,graph)) return false;
        }
        return true;
    }
};