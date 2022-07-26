class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &el : s)
        {
            if(el == '(' || el == '[' || el == '{')
                st.push(el);
            else
            {   if(st.size() == 0) return false;
                if(el == ')')
                {
                    if(st.top()!= '(') return false;
                }
                else if(el == ']')
                {
                    if(st.top()!= '[') return false;
                }
                else if(el == '}')
                {
                    if(st.top()!= '{') return false;
                }
                   st.pop(); 
            }
        }
        return st.size() == 0;
    }
};