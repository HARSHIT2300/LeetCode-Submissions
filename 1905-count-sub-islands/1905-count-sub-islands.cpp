class Solution {
public:
    bool vis[501][501];
    int ch[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    bool isValid(int x,int y,int &rows,int &cols)
    {
         if(x<0||y<0||x>=rows||y>=cols||vis[x][y]) return false;
        return true;
    }
    void dfs(int x,int y,vector<vector<int>> &grid1,vector<vector<int>> &grid2,int &rows,int &cols,int &f)
    {   
        if(!grid1[x][y]) f=0;
            
        vis[x][y]=1;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx = ch[i][0]+x; chy = ch[i][1]+y;
            if(isValid(chx,chy,rows,cols)&& grid2[chx][chy])
            dfs(chx,chy,grid1,grid2,rows,cols,f);
        }
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(vis,false,sizeof(vis));
        int ans=0;
        int rows = grid2.size(),cols=grid2[0].size(); 
        int f=1;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {   
                if(grid2[i][j]&&!vis[i][j])
                {
                    dfs(i,j,grid1,grid2,rows,cols,f) ;
                        if(f)
                        ans++;
                     f=1;
                    cout<<i<<" "<<j<<" "<<ans<<"\n";
                }
               
            }
        }
        return ans;
    }
};