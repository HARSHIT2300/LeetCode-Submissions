class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //MCM variation
        // solve the shorter versions, use them to solve the larger versions
        // shorter version means ans for the smaller window sizes is computed first and then the larger window sizes are considered... basically in increasing order of window sizes....
        // window size from 1 - N (possible left and right values for that window) - (possible values/indices that from left to right that could be chosen as the last balloon to be bursted)
        vector<int> v;
        v.push_back(1);
        for(auto &el : nums) v.push_back(el);
        v.push_back(1);
        int dp[v.size()][v.size()];
        memset(dp,0,sizeof(dp));
        for(int win_sz = 1; win_sz<=nums.size(); win_sz++)
        {
            for(int left = 1; left<=nums.size()-win_sz+1; left++)
            {
              int  right = left + win_sz -1;
                for(int lval = left;lval<=right;lval++)
                {
                    dp[left][right] = max(dp[left][right],dp[left][lval-1]+dp[lval+1][right]+(v[lval]*v[left-1]*v[right+1]));
                }
            }
        }
        return dp[1][nums.size()];
    }
};