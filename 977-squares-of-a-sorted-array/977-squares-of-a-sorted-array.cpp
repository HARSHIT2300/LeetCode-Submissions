class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l1,l2=0; int n=nums.size();
        while(l2<n && nums[l2]<0 ) l2++;
        l1 = l2-1;
        vector<int> ans;
        while(l1>=0 && l2 < n)
        {
            if(nums[l1]*nums[l1] <= nums[l2]*nums[l2])
            {ans.push_back(nums[l1]*nums[l1]); l1--;}
            else
            {ans.push_back(nums[l2]*nums[l2]); l2++;}
        }
        while(l1 >=0)
        {
            ans.push_back(nums[l1]*nums[l1]); l1--;
        }
        while(l2 < n)
        {
            ans.push_back(nums[l2]*nums[l2]); l2++;
        }
        return ans;
    }
};