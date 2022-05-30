int calc(int n,int target,vector<int>& nums,vector<vector<int>>& dp)
{
    if(dp[n][target] != -1)return dp[n][target];
    if(target == 0) return dp[n][target] =1;
    if(n == 0) return dp[n][target] = 0;
    if(nums[n-1]<=target)
        dp[n][target] = calc(n-1,target - nums[n-1],nums,dp) + calc(n-1,target,nums,dp);
    else
        dp[n][target] = calc(n-1,target,nums,dp);
    return dp[n][target];
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sm = 0;
        int ct = 0;
        // take into consideration the zeroes
        vector<int> nums1;
        for(auto &el : nums)
        {
              sm+=el;
            if(!el) ct++;
            else
                nums1.push_back(el);
        }
         ct =(int)pow(2,ct); 
        target+=sm; 
        if(target<0 || target & 1) return 0;
        if(!target) return 1*ct;
        target>>=1;
        vector<vector<int>> dp;
        vector<int> v(target+1,-1);
        int n = nums1.size();
        for(int i=0;i<=n;i++)
        {
            dp.push_back(v);
        }
        calc(n,target,nums1,dp);
        return dp[n][target]*ct;
    }
};