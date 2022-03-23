class Solution {
public:
   int m,n;
    int ch[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int dis[501][501];
    bool dfs(int x,int y, int &fx,int &fy,vector<vector<char>>& grid,bool vis[501][501],int d)
    {   // cout<<x<<" "<<y<<" "<<grid[x][y]<<"\n";
        vis[x][y] = 1;
        dis[x][y] = d;
        for(int i=0;i<4;i++)
        {
            int chx = ch[i][0]  + x;
            int chy = ch[i][1]  + y;
            if(chx>=0&&chx<m&&chy>=0&&chy<n)
            {
                if(grid[chx][chy] != grid[x][y]) continue;
                if(vis[chx][chy])
                {
                    if(d-dis[chx][chy] >= 3) return true;
                    continue;
                }
                if(dfs(chx,chy,fx,fy,grid,vis,d+1)) return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
         m =grid.size();
         n = grid[0].size();
        bool vis[501][501];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(vis[i][j]) continue;
                if(dfs(i,j,i,j,grid,vis,0)) return true;
            }
        }
        return false;
    }
};