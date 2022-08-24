class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        dp[0] = 0;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 1;j<=nums[i]&& i+j < nums.size(); j++)
            {
                dp[i+j] = min(dp[i+j],1+dp[i]);
            }
        }
        return dp[nums.size()-1];
    }
};