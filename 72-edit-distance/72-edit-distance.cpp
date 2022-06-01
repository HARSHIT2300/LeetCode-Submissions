#define INF 10000001
int calc(int i1,int i2,int &s1,int &s2,string &w1,string &w2,vector<vector<int>> &dp)
{
   
    if(i2 == s2) return dp[i1][i2] = s1-i1;
    if(i1 == s1) return dp[i1][i2] = s2-i2;
     if(dp[i1][i2] != INF) return dp[i1][i2];
    if(w1[i1] == w2[i2])
        dp[i1][i2] = calc(i1+1,i2+1,s1,s2,w1,w2,dp);
    else{
        dp[i1][i2] = min(dp[i1][i2],min(calc(i1+1,i2+1,s1,s2,w1,w2,dp),calc(i1,i2+1,s1,s2,w1,w2,dp))+1);
    dp[i1][i2] = min(dp[i1][i2],calc(i1+1,i2,s1,s2,w1,w2,dp)+1);
    }
    return dp[i1][i2];
}
class Solution {
public:
    int minDistance(string word1, string word2) {
      int s1 = word1.size(),s2 = word2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,INF));
        calc(0,0,s1,s2,word1,word2,dp);
        return dp[0][0];
    }
};