class Solution {
public:
    int rob(vector<int>& nums) {
        int max_money[nums.size()+1];
        max_money[0] = 0;
        max_money[1] = nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            max_money[i] = max(max_money[i-2]+nums[i-1],max_money[i-1]);
        }
        return max_money[nums.size()];
    }
};