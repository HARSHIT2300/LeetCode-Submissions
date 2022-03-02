class Solution {
public:
    bool vis[501][501];
    int ans;
    int ch[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    void fill(int x,int y,vector<vector<int>>& grid,int &rows,int &cols)
    {
        if(x<0||y<0||x>=rows||y>=cols) return ;
        if(vis[x][y]||!grid[x][y]) return ;
        vis[x][y]=1;
        grid[x][y]=0;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx = ch[i][0]+x; chy = ch[i][1]+y;
            fill(chx,chy,grid,rows,cols);
        }
    }
    void dfs(int x,int y,vector<vector<int>>& grid,int &rows,int &cols)
    {
        if(x<0||y<0||x>=rows||y>=cols) return ;
        if(vis[x][y] || !grid[x][y]) return ;
        vis[x][y] =1;
        ans++;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx = ch[i][0]+x; chy = ch[i][1]+y;
            dfs(chx,chy,grid,rows,cols);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       
        memset(vis,false,sizeof(vis));
        int rows=grid.size(),cols=grid[0].size();
        ans=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if((i==0||j==0||i==rows-1||j==cols-1)&& !vis[i][j] && grid[i][j]){
                    fill(i,j,grid,rows,cols); }
            }
        }
     
        for(int i=1;i<rows-1;i++)
        {
            for(int j=1;j<cols-1;j++)
            {
                if(!vis[i][j] && grid[i][j]){
                    dfs(i,j,grid,rows,cols);
                    
                }
            }
        }
        return ans;
    }
};