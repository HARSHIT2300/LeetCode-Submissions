class Solution {
public:
    bool vis[51][51];
    int ch[4][2] ={{1,0},{0,1},{-1,0},{0,-1}};
    int dfs(int x,int y,int &m,int &n,vector<vector<int>> &grid)
    {
        int ct =0;
        vis[x][y]=true;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx=x+ch[i][0];chy=ch[i][1]+y;
            if(chx>=0&&chx<m&&chy>=0&&chy<n&&!vis[chx][chy]&&grid[chx][chy])
                ct+=dfs(chx,chy,m,n,grid);
        }
        return ct+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&grid[i][j])
                    ans=max(ans,dfs(i,j,m,n,grid));
            }
        }
        return ans;
    }
};