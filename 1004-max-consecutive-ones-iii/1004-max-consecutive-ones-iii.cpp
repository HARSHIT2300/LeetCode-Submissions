class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        int n=nums.size();
        while(r<n)
        {
            if(!nums[r]) k--;
           
            while(k<0)
            {
                if(!nums[l++])k++;
              //  l++;
            }
            ans=max(ans,r-l+1);
            ++r;
        }
        return ans;
    }
};