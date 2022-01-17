class Solution {
public:
    int Kadane_Algo(vector<int> &nums)
    {
        int ans=nums[0],psum=nums[0],n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(psum+nums[i] > nums[i]) psum+=nums[i];
            else psum=nums[i];
            ans = max(ans,psum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
       int max_sum=Kadane_Algo(nums);
        int sm=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
         sm+=nums[i];
            nums[i]=-nums[i];
        }
       
        int min_sum = -Kadane_Algo(nums);
         //cout<<max_sum<<" "<<min_sum<<" ";
        if(sm-min_sum ==0) return max_sum;
        return max(max_sum,sm-min_sum);
    }
};