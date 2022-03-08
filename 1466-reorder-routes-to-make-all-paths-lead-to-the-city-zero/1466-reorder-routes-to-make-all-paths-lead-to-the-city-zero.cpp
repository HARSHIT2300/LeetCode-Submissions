class Solution {
public:
    void dfs(int node,int par,vector<vector<int>> &adj,int &ans)
    {
        for(auto &child : adj[node])
        {
            if(abs(child) == par) continue;
            if(child > 0) ans+=1;
            // if the value of child is +ve, it is indicating of a forward edge directed away from 0 hence this edge needs to reversed,add 1 to ans
            dfs(abs(child),node,adj,ans);
        }
        return ;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // The graph is a tree with n-1 nodes, be rest assured there will not be any cycles 
        vector<vector<int>> adj(n,vector<int>(0));
        for(auto &edge : connections)
        {
            adj[edge[0]].push_back(edge[1]);
            // + ve forward edge fron parent to child
            adj[edge[1]].push_back(-edge[0]);
             // - ve backward edge from child to parent
        }
        // visited array is not reqd as no cycles and each node except the root will have edges directed towards it think like a tree
        int ans=0;
        dfs(0,-1,adj,ans);
        return ans;
    }
};