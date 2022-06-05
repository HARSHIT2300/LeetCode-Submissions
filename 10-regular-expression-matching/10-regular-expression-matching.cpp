// not muchdifficult to understand but implementation heavy prob + some tricky edge cases need to be considered  eg  s = "a" , b = "ab*c*k*" should give true
// + intuition is basically started from the fact that if the next character in p is * ,then handle it differently... if ip is equal to len(p)-1 then it needs to be handled differently
// is = current index of s , ip  = current index of p,  ss  = length(s), p = length(p)


bool calc(int is,int ip,string &s,string &p,int &ss,int &ps,vector<vector<int>> &dp)
{  
    if(is == ss && ip == ps)
        return dp[is][ip] = 1;
    if( ip == ps) return dp[is][ip] = 0;
   if(is == ss)
   {
       if(ip == ps-1) return dp[is][ip] = 0;
       if(p[ip+1] == '*') return dp[is][ip] = calc(is,ip+2,s,p,ss,ps,dp);
       else return dp[is][ip] = 0;
   }
    if(dp[is][ip] != -1) return dp[is][ip];
    if(ip == ps-1)
    {
        if(p[ip] == s[is] || p[ip] == '.') 
                return dp[is][ip] = calc(is+1,ip+1,s,p,ss,ps,dp);
        return dp[is][ip] = 0;
    }
    if(p[ip+1] == '*')
    {  
        if (calc(is,ip+2,s,p,ss,ps,dp) == 1)
        return dp[is][ip]=1;
      dp[is][ip] = 0;
        int j = is;
        if(p[ip] == s[is] || p[ip] == '.')
        { 
            while(j<ss && (s[j] == p[ip] || p[ip] == '.'))
            { 
                if(calc(j+1,ip+2,s,p,ss,ps,dp) == 1){
                    return dp[is][ip] = 1;}
                j++;
            }
        }
    }
    else
    {
        if(p[ip] == s[is] || p[ip] == '.')
          return dp[is][ip] = calc(is+1,ip+1,s,p,ss,ps,dp);
        else
            return dp[is][ip] = 0;
    }
    return dp[is][ip];
}


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        int ss = s.size(),ps = p.size();
        calc(0,0,s,p,ss,ps,dp);
        return dp[0][0];
    }
};