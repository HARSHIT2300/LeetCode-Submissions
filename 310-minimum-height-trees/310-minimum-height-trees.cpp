class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        unordered_map<int,int> cache;
        if(n == 1){ans.push_back(0);return ans;}
        vector<int> deg(n,0);
        vector<int> adj[n];
        for(auto &edge : edges)
        {
            deg[edge[0]]++;
            deg[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i] == 1) {q.push(i); }
        }
        while(!q.empty())
        {
            int sz = q.size();
            ans.clear();
            while(sz){
            int node = q.front();
                q.pop();
            ans.push_back(node);
            for(auto &el : adj[node])
            {
                deg[el]--;
                if(deg[el] == 1)
                {
                    q.push(el);
                }
            }
                sz--;
            }
            
        }
        return ans;
    }
};