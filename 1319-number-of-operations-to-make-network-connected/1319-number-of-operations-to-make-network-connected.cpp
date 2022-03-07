class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // BFS
        int cc=0,ed=0;
        vector<int> adj[n];
        int a,b;
        for(auto edge : connections)
        {
            a=edge[0],b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool vis[n];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            cc++;
            int cn=0,te=0;
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                cn++;
                for(auto node : adj[curr])
                {
                  te++;
                    if(!vis[node]) {q.push(node);vis[node]=1;}
                }
                 
            }
           
            te/=2;
           
            ed+=(te-(cn-1));
        }
       
        if(cc-1 > ed) return -1;
        else return cc-1;
    }
};