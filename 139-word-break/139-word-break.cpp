class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto &el : wordDict)
        {
            mp[el]++;
        }
        int n = s.size();
        bool poss[n+1];
        memset(poss,false,sizeof(poss));
        poss[0] = 1;
        for(int end = 1; end<=n; end++)
        {   string s1= "";
            for(int start = end; start>=1 ; start--)
            {   s1 = s[start-1]+s1;
                if(poss[start-1])
                {
                    if(mp[s1]) {
                        poss[end] = 1;break;
                    }
                }
            }
        }
        return poss[n];
    }
};