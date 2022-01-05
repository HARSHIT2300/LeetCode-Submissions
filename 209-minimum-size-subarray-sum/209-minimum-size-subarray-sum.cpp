class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size(),ans=nums.size()+1,sm=0;
        while(r<n)
        {
            sm+=nums[r];
            while(sm>=target && l<=r){
                ans=min(ans,r-l+1);
                sm-=nums[l++];
            }
            ++r;
            
        }
        if(nums.size()+1 == ans) ans =0;
        return ans;
    }
};