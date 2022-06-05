bool calc(int is,int ip,string &s,string &p,int &ss,int &ps,vector<vector<int>> &dp)
{   // cout<<is<<" "<<ip<<"\n";
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
    {  // if(ip == 2 && is == 0) cout<<"!!!!";
        if (calc(is,ip+2,s,p,ss,ps,dp) == 1)
        return dp[is][ip]=1;
      dp[is][ip] = 0;
        int j = is;
        if(p[ip] == s[is] || p[ip] == '.')
        { 
            while(j<ss && (s[j] == p[ip] || p[ip] == '.'))
            { //cout<<j<<" "<<ip<<" "<<is<<"--";
                if(calc(j+1,ip+2,s,p,ss,ps,dp) == 1){
                    return dp[is][ip] = 1;}
                j++;
            }
        }
//         else if(p[ip] == '.')
//         {
           
//             while(j<ss)
//             {  
//                 if(calc(j+1,ip+2,s,p,ss,ps,dp) == 1)
//                     return dp[is][ip] = 1;
//                 j++;  
//             }
//         }
       
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
       //  for(auto &v : dp)
       //  {
       //      for(auto &el : v) cout<<el<<" ";
       //      cout<<"\n";
       //  }
       // cout<<dp[0][2]<<" "<<dp[2][2];
        return dp[0][0];
    }
};