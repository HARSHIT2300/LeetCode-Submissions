class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0,n=s.length();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else
                    st.push(i);
            }
        }
        if(st.empty()) return n;
        int r  = n;
        while(!st.empty())
        {
            ans = max(ans, r - st.top()-1);
            r = st.top();
            st.pop();
        }
        ans = max(ans,r);
        return ans;
    }
};