class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int deg[n];
        memset(deg,0,sizeof(deg));
        map<pair<int,int>,int> mp;
        for(auto &edge : roads)
        {
            deg[edge[0]]++;
            deg[edge[1]]++;
            mp[{edge[0],edge[1]}]=1;
             mp[{edge[1],edge[0]}]=1;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<n;j++)
            {   int f=0;
                if(j == i) continue;
                ans = max(ans,deg[i]+deg[j]-mp[{i,j}]);
            }
        }
        return ans;
    }
};