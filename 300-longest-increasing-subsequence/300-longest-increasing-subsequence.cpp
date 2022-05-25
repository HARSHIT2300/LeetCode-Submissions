void handler(int n,map<int,int> &mp)
{
    if(mp.size() == 0) 
    {
        mp[n] = 1; return ;
    }
    auto it = mp.lower_bound(n);
    if(it!=mp.end() && it->first == n) return ;
    if(it == mp.begin())
    {
        mp.erase(it);
        mp[n] = 1;
        return ;
    }
    it--; int adv = it->second+1;
    it = mp.upper_bound(n);
    if(it!= mp.end() && it->first>n)
        mp.erase(it);
    
    mp[n] = adv;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        map<int,int> lis;
        int n = nums.size();
        for(auto &el : nums)
        {
            handler(el,lis);
        //       for(auto &el : lis)
        // {
        //   cout<<el.first<<" "<<el.second<<"--";} cout<<"\n";
        // }
        }
        int ans = 1;
        for(auto &el : lis)
        {
        //  cout<<el.first<<" "<<el.second<<"\n";
            ans = max(ans,el.second);
        }
        return ans;
         
    }
};