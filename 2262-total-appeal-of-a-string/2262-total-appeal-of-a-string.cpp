class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        long long ans_end_at_i = 0;
        vector<long long> cache(27,-1);
        for(int i=0; i < s.length(); i++)
        {
            ans_end_at_i += i - cache[s[i] - 'a'];
            ans += ans_end_at_i;
            cache[s[i] - 'a'] = i;
        }
        return ans;
    }
};