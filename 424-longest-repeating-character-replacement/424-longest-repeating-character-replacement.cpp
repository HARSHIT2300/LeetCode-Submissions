class Solution {
public:
    int characterReplacement(string s, int k) {
        int cache[26];
        memset(cache,0,sizeof(cache));
        int n = s.size();
        int ans = 0;
        int max_ch=0;
        int start = 0;
        for(int end=0;end < n;end++)
        {
            cache[s[end] - 'A']+=1;
            max_ch = max(max_ch,cache[s[end] - 'A']);
            while(end-start + 1 - max_ch > k )
            {
                cache[s[start] - 'A']-=1;
                start++;
            }
           // cout<<ans<<" ";
            ans = max(ans,end - start+1);
        }
        return ans;
    }
};