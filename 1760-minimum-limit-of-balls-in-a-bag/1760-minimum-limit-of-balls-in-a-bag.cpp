class Solution {
public:
    int cost(int &n,vector<int> &nums)
    {   int cc = 0;
        for(auto &el : nums)
        {
           cc+=(el/n);
            if(el%n == 0) cc--;
        }
     return cc;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1,r=nums[0];
        for(auto &el : nums)
        {
            r = max(el,r);
        }
        int ans;
        while(l<=r)
        {
            int mid = l+((r-l)>>1);
            if(cost(mid,nums) <=maxOperations)
            {
                ans = mid;
                r = mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};