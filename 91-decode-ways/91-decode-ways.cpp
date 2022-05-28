int dfs(string s,int i,vector<int> &ans)
{
    if(ans[i] !=-1) return ans[i];
    if(i == s.size())
        return ans[i] = 1;
    if(s[i] == '0') return ans[i] = 0;
    int a =0;
   ans[i] = dfs(s,i+1,ans);
    if(i<s.length()-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' <= 6)))
        ans[i]+= dfs(s,i+2,ans);
    return ans[i];
    
}
// dp[i] will represnt/store the ans from index i(0-based) till the end of the string...
class Solution {
public:
    int numDecodings(string s) {
      vector<int> ans(s.size()+1,-1);
     int a = dfs(s,0,ans);
        return ans[0];
    }
};