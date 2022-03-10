class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,pair<int,int>>> q;
         set<pair<int,int>> sp;
        for(int i = 0;i<n;i++)
        {
            int mask_value = 1<<i;
            q.push({i,{mask_value,0}});
            sp.insert({i,mask_value});
        }
       
       while(!q.empty())
       {
           int node = q.front().first,mask_value = q.front().second.first,d = q.front().second.second; q.pop();
           for(auto &child : graph[node])
           {    
               int res_mask_value = mask_value | (1<<child) ;
               if(res_mask_value == (1<<n)-1) return d+1;
               if(sp.find({child,res_mask_value}) == sp.end())
               {
                   sp.insert({child,res_mask_value});
                   q.push({child,{res_mask_value,d+1}});
               }
           }
               
       }
        return 0;
    }
};