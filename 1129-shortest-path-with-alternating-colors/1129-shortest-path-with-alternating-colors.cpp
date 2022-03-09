class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // col 0 indicates graph made by red edges ,col 1 indicates graph made by blue edges
      // vector< vector<vector<int>> >  adj(2,vector<int>(n,vector<int>(0)));
        // vector<vector<vector<int> > > vec (5,vector <int>(3,vector <int>(2,4)));
        vector<vector<int>> adj1(n,vector<int>(0));
        vector< vector<vector<int>> >  adj;
        adj.push_back(adj1);  adj.push_back(adj1); 
        for(auto &v : redEdges)
        {
            adj[0][v[0]].push_back(v[1]);
            // adj[0][v[1]].push_back(v[0]);
        }
          for(auto &v : blueEdges)
        {
            adj[1][v[0]].push_back(v[1]);
            // adj[1][v[1]].push_back(v[0]);
        }
        //How to think/understand? ans[0][node] indicates the that the node 0 belongs to the red graph and and ans[1][node] indicates that the node 1 belongs to the blue bag
    // also remember that if the current node value is of colour 0 all the corresponding updates of distance and pushing the child to the queue will be done with the child colour being 1 because the question has mentioned alternate colours
        queue<pair<int,int>> q;
        q.push({0,1});
        q.push({0,0});
        // exploring each of the 2 possibilities that that 1st node,i.e, 0/1 can have edges starting from it to be red/blue respectively
     vector<vector<int>> dis(2,vector<int>(n,INT_MAX));
      dis[0][0]=0; dis[1][0]=0;
        vector<int> res(n,0);
        while(!q.empty())
        {
            int node = q.front().first,col = q.front().second;
            q.pop();
            for(auto &child : adj[col][node])
            {
                if(dis[col^1][child] == INT_MAX)
                { 
                    dis[col^1][child] = dis[col][node]+1;
                    q.push({child,col^1});
                }
            }
          }
        // we calculate the min of the dis of each nodes out of the 2 colours and assign it to res for that node's value. 
          for(int i=1;i<n;i++)
            {
                int a = min(dis[0][i],dis[1][i]);
                res[i] =  a == INT_MAX ? -1 : a;
            }
        return res;
    }
    
};