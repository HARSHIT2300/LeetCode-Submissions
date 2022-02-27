class Solution {
public:
    bool vis[101][101];
    int ch[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    void fill_edgezero_one(int x,int y,int& m,int& n,vector<vector<int>>& grid)
    {
        if(x<0||y<0||x==m||y==n)return ;
        if(vis[x][y]||grid[x][y]) return ;
        grid[x][y]=1; vis[x][y]=1;
        int chx,chy;
        for(int i=0;i<4;i++)
        {   chx = x+ch[i][0]; chy = y+ch[i][1];
                fill_edgezero_one(chx,chy,m,n,grid);
        }
    }
    bool dfs(int x,int y,int m,int n,vector<vector<int>>& grid)
    {
        if(x==0||y==0||x==m||y==n) return false;
        vis[x][y]=true;
       // cout<<x<<" "<<y<<"\n";
       // if(x==1&&y==2) cout<<vis[3][3]<<"\n";
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx = x+ch[i][0]; chy = y + ch[i][1];
            if(!vis[chx][chy]&&!grid[chx][chy]) 
            {
                if(!dfs(chx,chy,m,n,grid)) return false;
            }
        }
        return true;
    }
    int closedIsland(vector<vector<int>>& grid) {
    memset(vis,false,sizeof(vis));
        int m = grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1&&!vis[i][j])
                {
                    fill_edgezero_one(i,j,m,n,grid);
                }
            }
        }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(!grid[i][j]&&!vis[i][j])
            {      
                if(dfs(i,j,m-1,n-1,grid)) 
                    ans++;
            }
        }
    }
        return ans;
    }
};