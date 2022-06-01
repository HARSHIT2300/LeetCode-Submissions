int calc(int is,int it,string& s,string& t,vector<vector<int>>& dp,int &ss,int &ts)
{
   if(dp[is][it] != -1) return dp[is][it];
    if(it == ts) return dp[is][it] = 1;
    if(is == ss) return dp[is][it] = 0;
     
    if(s[is] == t[it])
        dp[is][it] = calc(is+1,it+1,s,t,dp,ss,ts) + calc(is+1,it,s,t,dp,ss,ts);
    else
        dp[is][it] = calc(is+1,it,s,t,dp,ss,ts);
    return dp[is][it];
}

class Solution {
public:
    int numDistinct(string s, string t) {
      //  if(s.size()<t.size()) return 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));  
        int ss = s.size(),ts = t.size();
          calc(0,0,s,t,dp,ss,ts);
        return dp[0][0];
    }
};