class Solution {
public:
    unordered_map<int,int> cn;
    bool dfs(int node,int par,vector<vector<int>> &graph,bool vis[],int col[])
    {   vis[node]=1;
        col[node]=1;
        for(auto &curr : graph[node])
        {
            if(!vis[curr]){
                if(dfs(curr,par,graph,vis,col))
                    cn[node]=1;
            }
            else
            {
                if(col[curr]||cn[curr])
               cn[node]=1;
            //    cout<<node<<" "<<curr<<"\n";
            }
        }
     col[node]=0;
        return cn[node]==true;   
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<int> ans;
        int n = graph.size();
        bool vis[n]; int col[n];
        memset(vis,false,sizeof(vis));
         memset(col,false,sizeof(col));
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(!graph[i].size()) continue;
         if(!vis[i]){ dfs(i,i,graph,vis,col); ct++;}
        
        }
  //  cout<<ct<<" ";
        for(int i=0;i<n;i++)
        {
            if(!cn[i]) ans.push_back(i);
             // cout<<cn[i]<<" "<<col[i]<<"\n";
         
        }
        return ans;
    }
};