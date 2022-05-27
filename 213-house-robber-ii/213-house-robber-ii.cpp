int calc(vector<int>& nums,int low,int high)
{  
    if(high == low) return nums[low];
     //high and low both are 0-indexed based
    int dp[high+2];
    dp[low+1] = nums[low];
    dp[low] = 0;
    for(int pos = low+2;pos<=high+1;pos++)
    {
        dp[pos] = max(dp[pos-1],dp[pos-2]+nums[pos-1]);
    }
    return dp[high+1];
}
class Solution {
public:
    int rob(vector<int>& nums) {
         if(nums.size() == 1) return nums[0];
        return max(calc(nums,0,nums.size()-2),calc(nums,1,nums.size()-1));
    }
};