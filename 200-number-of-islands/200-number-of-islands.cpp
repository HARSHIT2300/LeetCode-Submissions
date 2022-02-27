class Solution {
public:
    int ch[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    bool vis[301][301];
    void dfs(int x,int y,int &m,int &n,vector<vector<char>>& grid)
    {
        vis[x][y]=true;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx=ch[i][0]+x,chy=y+ch[i][1];
            if(chx>=0&&chx<m&&chy>=0&&chy<n&&!vis[chx][chy]&&grid[chx][chy]=='1')
                dfs(chx,chy,m,n,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,false,sizeof(vis));
        int ans = 0;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j]) {ans+=1; dfs(i,j,m,n,grid);}
            }
        }
        return ans;
    }
    
};