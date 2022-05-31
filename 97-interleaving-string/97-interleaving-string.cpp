bool calc(int i1,int i2,string s1,string s2,string s3,vector<vector<int>> &dp)
{
   
    if(i1 == s1.size() && i2 == s2.size())
        return dp[i1][i2] = 1;
     if(dp[i1][i2] != -1) return dp[i1][i2];
    if(i1 == s1.size())
    {
        if(s2[i2] != s3[i1+i2]) 
            return dp[i1][i2] = 0;
     dp[i1][i2] = calc(i1,i2+1,s1,s2,s3,dp);
    }
    else if(i2 == s2.size())
    {
     if(s1[i1] != s3[i1+i2]) 
            return dp[i1][i2] = 0;
     dp[i1][i2] = calc(i1+1,i2,s1,s2,s3,dp);   
    }
    else
    {
        if(s1[i1] == s3[i1+i2] && s2[i2] == s3[i1+i2])
            dp[i1][i2] = calc(i1+1,i2,s1,s2,s3,dp) | calc(i1,i2+1,s1,s2,s3,dp);
        else if(s1[i1] == s3[i1+i2])
             dp[i1][i2] = calc(i1+1,i2,s1,s2,s3,dp);
        else if(s2[i2] == s3[i1+i2])
             dp[i1][i2] = calc(i1,i2+1,s1,s2,s3,dp);
        else
            dp[i1][i2] = 0;
    }
    return dp[i1][i2];
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        calc(0,0,s1,s2,s3,dp);
        return dp[0][0];
    }
};