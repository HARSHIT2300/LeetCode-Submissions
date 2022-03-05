class Solution {
public:
    int ch[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int &x,int &y,int &n)
    {
        if(x>=0&&x<n&&y>=0&&y<n) return true;
        else return false;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q,q1;
        int n = grid.size();
        int vis[n][n];
           int dis[n][n];
        memset(vis,0,sizeof(vis));
         memset(dis,-1,sizeof(dis));
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]){
                    q.push({i,j});   q1.push({i,j}); vis[i][j]=1; dis[i][j]=0; 
                    f=1;
                    break;}
            }
            if(f)break;
        }
      
        int chx,chy;
        while(!q.empty())
        {
            int x= q.front().first,y = q.front().second;
          q.pop();
        for(int i=0;i<4;i++)
        {
            chx = x+ch[i][0],chy = y+ch[i][1];
            if(isValid(chx,chy,n) && !vis[chx][chy] && grid[chx][chy]){ q.push({chx,chy});
            q1.push({chx,chy}); vis[chx][chy]=1; dis[chx][chy]=0;
                                                                  }
            
        }
        }
        int ans = INT_MAX;
        while(!q1.empty())
        {
              int x= q1.front().first,y = q1.front().second;
          q1.pop();
        for(int i=0;i<4;i++)
        {
            chx = x+ch[i][0],chy = y+ch[i][1];
            if(isValid(chx,chy,n) && dis[chx][chy]==-1 )
            {
                    dis[chx][chy]=dis[x][y]+1;
                 if(!grid[chx][chy])
                    q1.push({chx,chy});
                else //ans=min(ans,dis[chx][chy]);
                return dis[chx][chy]-1;
            }
            
        }
        }
     
        return ans-1;
    }
};