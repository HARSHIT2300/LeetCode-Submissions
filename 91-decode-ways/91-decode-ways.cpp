/* int dfs(string s,int i,vector<int> &ans)
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
// Bottom Up Recursive
*/

// dp[i] will represnt/store the ans from index i(0-based) till the end of the string...
class Solution {
public:
// Top down iterative
    int numDecodings(string s) {
      vector<int> ans(s.size()+1,-1);
    // int a = dfs(s,0,ans);
        int n = s.size();
        ans[n] = 1;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i] == '0')
                ans[i] = 0;
            else
                ans[i] = ans[i+1];
            if(i!=n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1]-'0' <= 6)))
                ans[i]+=ans[i+2];
        }
        return ans[0];
    }
};