class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int i=0,ans=0;
        for(auto &el : s)
        {   ++i;
            if(el == '(') st.push(i);
         else
         {
             if(st.empty()) ans++;
             else st.pop();
         }
        }
        ans+=st.size();
        return ans;
    }
};