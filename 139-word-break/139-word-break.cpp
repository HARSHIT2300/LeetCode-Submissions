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
        {
            for(int start = 1; start<=end ; start++)
            {
                if(poss[start-1])
                {
                    if(mp[s.substr(start-1,end-start+1)]) {
                        poss[end] = 1;break;
                    }
                }
            }
        }
        return poss[n];
    }
};