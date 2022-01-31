class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int  ans=0;
        int m = accounts.size(),n=accounts[0].size();
        for(auto &v : accounts)
        {   int sm=0;
            for(auto &el  : v)
                sm+=el;
         ans=max(ans,sm);
        }
        return ans;
    }
};