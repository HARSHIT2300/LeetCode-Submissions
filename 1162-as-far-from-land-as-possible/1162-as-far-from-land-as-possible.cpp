class Solution {
public:
    int ch[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    bool isValid(int &x,int &y,int &n)
    {
        if(x<0||y<0||x>=n||y>=n) return false;
        else return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
     int ans=1;  
        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(grid[i][j])
                 q.push({{i,j},ans});
         }
     }
      //  if(q.size() == 0) return -1;
        int chx,chy;
        while(!q.empty())
        {
            int x = q.front().first.first,y=q.front().first.second,d=q.front().second;
            q.pop(); 
            ans=max(ans,d);
            for(int i=0;i<4;i++)
            {
                chx = x + ch[i][0];
                chy = y + ch[i][1];
              
                if(isValid(chx,chy,n)&& !grid[chx][chy]){
                   
                    q.push({{chx,chy},d+1}); grid[chx][chy] =d;}
            }
        }
       return  ans == 1 ? -1 : ans-1;
    }
};