class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        bool vis[n+1];
        memset(vis,true,sizeof(vis));
        int in[n+1];
        memset(in,0,sizeof(in));
        for(auto &v : trust)
        {
            in[v[1]]++;
            vis[v[0]]=false;
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(in[i] == n-1 && vis[i])
            {
                if(ans != -1)return -1;
                ans =i;
            }
           
        }
        return ans;
    }
};