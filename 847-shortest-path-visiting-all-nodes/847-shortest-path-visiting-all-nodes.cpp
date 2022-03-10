class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,pair<int,int>>> q;
         bool vis[n][1<<12];
        memset(vis,false,sizeof(vis));
        for(int i = 0;i<n;i++)
        {
            int mask_value = 1<<i;
            q.push({i,{mask_value,0}});
           vis[i][mask_value]=1;
        }
       
       while(!q.empty())
       {
           int node = q.front().first,mask_value = q.front().second.first,d = q.front().second.second; q.pop();
           for(auto &child : graph[node])
           {    
               int res_mask_value = mask_value | (1<<child) ;
               if(res_mask_value == (1<<n)-1) return d+1;
               if(!vis[child][res_mask_value])
               {
                   vis[child][res_mask_value]=1;
                   q.push({child,{res_mask_value,d+1}});
               }
           }
               
       }
        return 0;
    }
};