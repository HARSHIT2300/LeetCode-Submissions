class Solution {
public:
    void dfs(int node,bool vis[],vector<vector<int>>& rooms,int &ct)
    {
        vis[node]=1;
     
        ct++;
        for(auto &child : rooms[node])
        {
            if(!vis[child]) dfs(child,vis,rooms,ct); 
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        bool vis[n];
        memset(vis,false,sizeof(vis));
        
        int ct=0;
        dfs(0,vis,rooms,ct);
      
        return ct == n;
    }
};