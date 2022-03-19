class Solution {
public:
    bool dfs(string src,string des, unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,bool> &vis,double val,double &ans)
    {
        vis[src] =true;
      //  cout<<src<<" "<<val<<" ";
        if(src == des)
        {  
            if(ans!=-1.0) return false;
             ans = val;
           // cout<<val<<"\n";
            return true;
        }
        for(auto nodewt : adj[src])
        {
            string node = nodewt.first; double node_val = nodewt.second;
            if(vis[node]) continue;
            val*=node_val;
            if(!dfs(node,des,adj,vis,val,ans)) return false;
            val/=node_val;
        }
       // val=1.0;
        return true;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        unordered_map<string,bool> vis;
        int n = equations.size();
        for(int i=0;i<n;i++)
        {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
            vis[equations[i][0]]=false;
             vis[equations[i][1]]=false;
        }
        vector<double> res;
        for(auto &edge : queries)
        {
            double ans = -1.0;
            if(vis.count(edge[0])&&vis.count(edge[1])){
         if(!dfs(edge[0],edge[1],adj,vis,1.0,ans)) ans = -1.0;   
            }
         //  cout<<"\n";
            res.push_back(ans);
            for(auto &el : vis)
            {
                el.second = false;
            }
        }
        return res;
    }
};