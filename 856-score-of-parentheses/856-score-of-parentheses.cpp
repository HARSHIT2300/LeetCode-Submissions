class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st; int n= s.length();
        st.push(0);
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(0);
            }
            else
            {
                int a = st.top();
                if(a == 0) a =1;
                else a*=2;
                st.pop();
                st.top() += a;
            }
        }
        return st.top();
    }
};