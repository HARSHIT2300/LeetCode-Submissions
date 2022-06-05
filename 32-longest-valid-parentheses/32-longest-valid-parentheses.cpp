class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()+1];
        memset(dp,0,sizeof(dp));
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            if(s[i-1] == '(')
            {
                st.push(i);
                if(i == 1 || s[i-2] == ')')
                dp[i]  = dp[i-1];
                else dp[i] =0;
            }
            else
            {
                if(st.empty())
                    dp[i] = 0;
                else
                {
                    int a = st.top(); st.pop();
                    dp[i]  = dp[a]+i-a+1;
                }
            }
           // cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);//cout<<st.size()<<" ";
        }
        return ans;
    }
};