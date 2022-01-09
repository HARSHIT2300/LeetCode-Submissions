class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(auto &s : sentences)
        {
            int pos = s.find(' ');
            int res = 0;
            while(pos!=-1)
            {
                res++;
                pos = s.find(' ',pos+1);
            }
            res++;
            ans = max(ans,res);
        }
        return ans;
    }
};