class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int ans=0;
    int n = s.length();
     int mp[200];
        memset(mp,0,sizeof(mp));
        int l=0,r=0;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp[s[r]]>1 ){--mp[s[l++]];}
           // cout<<ans<<" "<<l<<" "<<r<<"\n";
            ans = max(r-l+1,ans);
            r++;
        }
        return ans;
    }
};