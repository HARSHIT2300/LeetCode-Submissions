class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &el : nums) mp[el]++;
        int ans = 0;
        for(auto &el : nums)
        {
            if(el>=k) continue;
            if(el == k - el)
            {
                if(mp[el] >= 2)
                {
                    ans++; mp[el]-=2;
                }
            }
            else if(mp[k-el] && mp[el])
            {
               
                mp[k - el]--;mp[el]--; ans++;
            }
        }
        return ans;
    }
};