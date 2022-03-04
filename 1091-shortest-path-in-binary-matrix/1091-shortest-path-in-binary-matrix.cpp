class Solution {
public:
    bool isValid(int x,int y,int &n)
    {
        if(x>=0&&x<n&&y>=0&&y<n) return true;
        else return false;
    }
  int ch[8][2] ={{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1}};
  
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        int ans=0;
        int dis[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dis[i][j]=10001;
            }
        }
      queue<pair<int,int>> q;
        q.push({0,0}); dis[0][0]=1;
        int f=0;
        while(!q.empty())
        {
            int x = q.front().first,y=q.front().second;
            q.pop(); int chx,chy;
           //   if(x == n-1 && y == n-1){return dis[x][y];}
            for(int i=0;i<8;i++)
            {
                chx = x+ch[i][0],chy=y+ch[i][1];
                if(isValid(chx,chy,n) && !grid[chx][chy] && dis[chx][chy] == 10001)
                {   q.push({chx,chy});
                    dis[chx][chy] = dis[x][y]+1;
                 
                }
            }
        }
       // cout<<dis[n-1][n-1]<<" ";
        return dis[n-1][n-1]!=10001 ? dis[n-1][n-1] : -1;
    }
};