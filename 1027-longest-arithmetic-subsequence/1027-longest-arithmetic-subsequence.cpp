class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(1002,1));
        int ans = 1;
        for(int end = 1; end<nums.size(); end++)
        {
            for(int start = 0;start<end; start++)
            {   int diff = nums[end] - nums[start];
                if(diff < 0)
                    diff+=1001;
                dp[end][diff] = dp[start][diff]+1;
          //   cout<<dp[end][diff]<<" ";
             ans = max(ans,dp[end][diff]);
            }
           // cout<<"\n";
        }
        return ans;
    }
};