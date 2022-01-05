class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        int cnt = 0,ans =0;
      //  vector<int> cnt;
        while(r<n)
        {
            if(nums[r]%2){k--; cnt = 0;}
            while(k == 0)
            {
                if(nums[l] % 2) k++;
                l++; cnt++;
                
            }
           ans+=cnt;
            r++;
        }
        return ans;
    }
};