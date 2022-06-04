class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int maxp=0,maxn=0;
        vector<int> v;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] - nums[i-1] != 0)
            v.push_back(nums[i]-nums[i-1]);
        }
        
        for(auto &el : v)
        {
            if(el > 0)
                maxp = max(maxn+1,maxp);
            else
                maxn = max(maxp+1,maxn);
        }
        return max({maxn,maxp})+1;
    }
};