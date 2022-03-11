class Solution {
public:
    void func(int i,vector<int> &nums,vector<int> res,set<vector<int>> &ans)
    {
        if(i == nums.size())
        {
            ans.insert(res);
            return ;
        }
        func(i+1,nums,res,ans);
        res.push_back(nums[i]);
        func(i+1,nums,res,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        func(0,nums,res,ans);
        vector<vector<int>> ans1;
        for(auto &v : ans)
        {
            ans1.push_back(v);
        }
        return ans1;
    }
};