class Solution {
public:
    int ch[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
    bool isValid(int &x,int &y,int &m,int &n)
    {
        if(x>=0&&x<m&&y>=0&&y<n) return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n=maze[0].size();
        int dis[m][n];
        memset(dis,-1,sizeof(dis));
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        dis[entrance[0]][entrance[1]]=0;
        int chx,chy;
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                chx = x+ch[i][0],chy=y+ch[i][1];
                if(isValid(chx,chy,m,n) && maze[chx][chy] == '.' && dis[chx][chy] == -1)
                {
                    dis[chx][chy] = dis[x][y]+1;
                    if(chx==0 || chx == m-1 || chy == 0 || chy == n-1) return dis[chx][chy];
                    q.push({chx,chy});
                }
            }
        }
        return -1;
    }
};