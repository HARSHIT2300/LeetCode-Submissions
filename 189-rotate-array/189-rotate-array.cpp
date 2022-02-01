class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(nums.size(),0);
        k%=n;
        for(int i=0;i<n;i++)
        {
            int idx = i-k;
            if(idx<0) idx+=n;
            ans[i] = nums[idx];
        }
        nums = ans;
      //  return ans;
    }
};