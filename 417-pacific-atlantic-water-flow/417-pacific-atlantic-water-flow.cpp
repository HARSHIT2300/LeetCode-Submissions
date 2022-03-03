class Solution {
public:
    int ch[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int x,int y,vector<vector<int>> heights,vector<vector<bool>> &vis,int &m,int &n)
    {
        vis[x][y]=1;
        int chx,chy;
        for(int i=0;i<4;i++)
        {
            chx = x+ch[i][0];
            chy= y+ch[i][1];
            if(chx>=0&&chx<m&&chy>=0&&chy<n&& !vis[chx][chy] && heights[chx][chy]>=heights[x][y])
                dfs(chx,chy,heights,vis,m,n);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // [][][0] - pacific    [][][1] - atlantic
        int m = heights.size();
        int n = heights[0].size();
          vector<vector<int>> ans;
        if(m==1||n==1)
        {
          for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { 
                   vector<int> v={i,j};
                    ans.push_back(v);
                    
            }
        }   
            return ans;
        }
        
        vector<vector<bool>> vis1(m,vector<bool>(n,false)),vis2(m,vector<bool>(n,false));
      
       
     for(int i=0;i<m;i++) {
        if(!vis1[i][0]) dfs(i,0,heights,vis1,m,n);
         if(!vis2[i][n-1])dfs(i,n-1,heights,vis2,m,n);
     
     }
        for(int i=0;i<n;i++) {
        if(!vis1[0][i]) dfs(0,i,heights,vis1,m,n);
         if(!vis2[m-1][i])dfs(m-1,i,heights,vis2,m,n);
     
     }
        
      
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(vis1[i][j]&&vis2[i][j])
                {   vector<int> v={i,j};
                    ans.push_back(v);
                }
                    
            }
        
        }
        return ans;
    }
};