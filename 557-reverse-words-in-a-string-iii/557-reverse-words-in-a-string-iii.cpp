class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        s+=" ";
        string s1="",ans="";
        for(int i=0;i<=n;i++)
        {
            if(s[i] == ' ')
            {
                ans+=s1;
                if(i==n) break;
                ans+=" "; s1="";
            }
            else s1=s[i]+s1;
        }
        return ans;
    }
};