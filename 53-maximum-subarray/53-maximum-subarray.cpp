class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int psum = 0;
        int ans = -10006;
        for(auto &el : nums)
        {
            ans = max(ans,psum+el);
            if(psum+el>0) psum+=el;
            else psum =0;
        }
        return ans;
    }
};