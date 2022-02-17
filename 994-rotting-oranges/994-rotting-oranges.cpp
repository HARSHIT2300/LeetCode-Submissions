class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
      int ans = 0;
        queue<vector<int>> q;
        vector<vector<int>> diff = {{-1,0},{1,0},{0,1},{0,-1}};
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(grid[i][j] == 2) q.push({i,j,0});  
            }
        }
        while(!q.empty())
        {   
            vector<int> v = q.front(); q.pop();
            ans = max(ans,v[2]);
             for(int i=0;i<diff.size();i++)
            {
            int chx = v[0]+diff[i][0],chy = v[1]+diff[i][1];
            if(chx>=0&&chx<m&&chy>=0&&chy<n&&grid[chx][chy] == 1)
            {
                grid[chx][chy]=2;
                q.push({chx,chy,v[2]+1});
            }
                
            }
        }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(grid[i][j] == 1) return -1;  
            }
        }
        return ans;
    }
};