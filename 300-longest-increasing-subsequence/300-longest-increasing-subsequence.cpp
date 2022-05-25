void handler(int n,map<int,int> &mp)
{
    if(mp.size() == 0) 
    {
        mp[n] = 1; return ;
    }
    auto it = mp.lower_bound(n);

    if(it!=mp.end() && it->first == n) return ;
    // if the value n  already exists in the lis, no point of taking it into consideration again as the lis will not change/get affected
    
    if(it == mp.begin())
    {
        mp.erase(it);
        mp[n] = 1;
        return ;
    }
    it--; int adv = it->second+1;
    it = mp.upper_bound(n);
    
    if(it!= mp.end() && it->first>n) // if current element,n, is smaller than the upper bound of n , we remove the upper bound of n as  now with a smaller element ,i.e n we can have the same advantage and this seems like an more intuitive task that could possibily improve our chances of getting a larger lis while taking into consideration the subsequent unknown numbers that would coming in nums ....
        mp.erase(it);
    
    mp[n] = adv;
}
// lis is an increasing sequence that we are maintaing
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        map<int,int> lis;
        int n = nums.size();
        for(auto &el : nums)
        {
            handler(el,lis);
    
        }
        int ans = 1;
        for(auto &el : lis)
        {
      
            ans = max(ans,el.second);
        }
        return ans;
         
    }
};