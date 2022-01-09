class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(1,nums[0]);
        deque<int> dq; dq.push_back(nums[0]);
        int n = nums.size();
        int ans = nums[0];
        for(int i=1;i<n;i++)
        {
            if(i>k && dq[0] == dp[i-k-1]) dq.pop_front();
            dp.push_back(max(nums[i],dq[0]+nums[i]));
            ans = max(dp[i],ans);
            while(!dq.empty() && dq.back() < dp[i])dq.pop_back();
            dq.push_back(dp[i]);
        }
        return ans;
    }
};