class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
       int ans = 0,l=0,r=0;
        vector<int> cnt(256,-1);
        for(auto &el : s)
        {
            if(cnt[el]>=l)
            {
                l=cnt[el]+1;
               
            }
                 cnt[el]=r;
            ans=max(ans,r-l+1);
                ++r;
        }
        return ans;
    }
};