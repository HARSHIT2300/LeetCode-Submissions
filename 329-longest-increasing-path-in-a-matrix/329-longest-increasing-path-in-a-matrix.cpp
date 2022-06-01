int ch[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool isValid(int &i,int &j,int &m,int &n)
{
   if(i<0||j<0||i==m||j==n) return 0;
    return 1;
}
int calc(int x,int y,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp)
{
  
    if(dp[x][y] != -1) return dp[x][y];
    int chx,chy;
    for(int i=0;i<4;i++)
    {
        chx = x  + ch[i][0]; chy = y  + ch[i][1];
        if(isValid(chx,chy,m,n) && matrix[chx][chy] > matrix[x][y])
            dp[x][y] = max(dp[x][y],calc(chx,chy,m,n,matrix,dp)+1);
    }
    dp[x][y] = max(1,dp[x][y]);
    return dp[x][y];
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j] == -1){
                    calc(i,j,m,n,matrix,dp);
                    ans = max(ans,dp[i][j]);
                }
                
            }
        }
        return ans;
    }
};