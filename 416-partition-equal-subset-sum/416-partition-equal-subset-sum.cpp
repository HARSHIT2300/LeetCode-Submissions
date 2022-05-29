int calc(vector<int>&nums,int i,int sm,vector<int>& dp)
{
    if(sm == 0) return 1;
   if(sm<0 || i == nums.size()) return 0;
    if(dp[sm] !=-1) return dp[sm];
    dp[sm] = calc(nums,i+1,sm-nums[i],dp) || calc(nums,i+1,sm,dp);
    return dp[sm];
   
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto &el : nums) target+=el;
        if(target&1) return false;
        target>>=1;
        vector<int> dp(20004,-1);
        dp[0] = 1;
        calc(nums,0,target,dp);  
      //  for(int i=1;i<100;i++) cout<<dp[i]<<" ";
     //   cout<<dp[target]<<" "<<target<<" ";
        return dp[target];
    }
};