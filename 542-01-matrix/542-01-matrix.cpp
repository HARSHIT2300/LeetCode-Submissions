class Solution {
public:
    int ch[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int &x,int &y,int &m,int &n)
    {
        if(x>=0&&x<m&&y>=0&&y<n) return true;
        else return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(); int chx,chy;
        vector<vector<int>> dis(m,vector<int>(n,0));
    
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   if(mat[i][j] == 0 || dis[i][j]) continue;
                for(int k=0;k<4;k++)
                {       chx = i+ch[k][0],chy = j+ch[k][1];
                    if(isValid(chx,chy,m,n) && !mat[chx][chy] )
                    {
                        dis[i][j]=1; q.push({i,j});
                        break;
                    }
                }
            }
        }
        while(!q.empty())
        {
            int x = q.front().first,y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                chx = x+ch[i][0],chy = y+ch[i][1];
                if(isValid(chx,chy,m,n) && mat[chx][chy] && !dis[chx][chy])
                {
                    dis[chx][chy] = dis[x][y]+1;
                    q.push({chx,chy});
                }
            }
        }
        return dis;
    }
};