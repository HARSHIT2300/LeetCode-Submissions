class Solution {
public:
    bool dfs(vector<int>& arr,int node,bool vis[])
    {
     //   if(node<0||node>=arr.size()||vis[node]) return false;
        vis[node]=true;
        //cout<<node<<" ";
        if(arr[node] == 0) return true;
      //  vis[node] =true;
        if((node+arr[node]<arr.size()&&!vis[node+arr[node]]&&dfs(arr,node+arr[node],vis))||(node-arr[node]>=0&&!vis[node-arr[node]]&&dfs(arr,node-arr[node],vis)))
            return true;
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        bool vis[arr.size()];
        memset(vis,false,sizeof(vis));
      return  dfs(arr,start,vis);
        
    }
};