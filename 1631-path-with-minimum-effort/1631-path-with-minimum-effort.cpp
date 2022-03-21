class Solution {
public:
    int ch[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(int r,int c,int &m,int &n,vector<vector<int>>& heights,bool vis[101][101],int &val)
    {
        vis[r][c] =1;
        if(r == m-1 && c == n-1) return true;
        
        for(int i=0;i<4;i++)
        {
            int chx = ch[i][0] + r;
            int chy = ch[i][1] + c;
            if(chx>=0&& chx< m && chy>=0 && chy<n){
            if( vis[chx][chy]) continue;
            
            if(abs(heights[chx][chy]-heights[r][c])<=val && dfs(chx,chy,m,n,heights,vis,val)) return true;
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int mn = 1000000,mx = 1;
        int m = heights.size();
        int n = heights[0].size();
     for(auto &row : heights)
     {
         for(auto &el : row)
         {
             mx = max(el,mx);
             mn = min(el,mn);
         }
     }
        int l = 0,h = mx - mn;
        bool vis[101][101];
        int ans;
        while(l<=h)
        {   memset(vis,false,sizeof(vis));
            int mid = l+((h-l)>>1);
            if(dfs(0,0,m,n,heights,vis,mid))
            {
                ans = mid; h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};