class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || s.size() < k) return 0;
        
        vector<int> cnt(26,0);
        for(auto &el : s) cnt[el-'a']++;
        int idx = 0;
        while(idx<s.size() && cnt[s[idx]-'a']>=k  ) idx++;
        if(idx == s.size()) return s.size();
        int left = longestSubstring(s.substr(0,idx), k);
        while(  idx<s.size() && cnt[s[idx]-'a']<k ) idx++;
         int right = longestSubstring(s.substr(idx), k);
        return max(left,right);
    }
};