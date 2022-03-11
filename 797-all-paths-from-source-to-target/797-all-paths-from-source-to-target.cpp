class Solution {
public:
    void dfs(int node,bool vis[],vector<int> res,vector<vector<int>> &ans,vector<vector<int>> &graph)
    {
     //   vis[node] =1;
        res.push_back(node);
        if(node == graph.size()-1){ ans.push_back(res); return;}
            for(auto &child : graph[node])
            {
                //if(vis[child]) continue;
                dfs(child,vis,res,ans,graph);
            }
       
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n =graph.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        vector<vector<int>> ans;
        vector<int> res;
        dfs(0,vis,res,ans,graph);
        return ans;
    }
};