class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        map<int,int> mp;
        int sm = 0;
        sort(nums.begin(),nums.end());
        int ct = 1;
        for(auto &el : nums)
        {
            sm+=el;
            mp[sm] = ct;
            ++ct;
        }
        vector<int> ans;
        ct = 0;
        for(auto &q : queries)
        {
            auto it = mp.upper_bound(q);
            if(it != mp.begin())
            {
                it--;
                ans.push_back(it->second);
            }
           else ans.push_back(0);
        }
        return ans;
    }
};