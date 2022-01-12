class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
      unordered_map<int,int> ob,cb;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(st.empty()) s[i] = '*';
                else st.pop();
            }
            else
            {
                continue;
            }
        }
        while(!st.empty()){ s[st.top()] = '*'; st.pop();}
        string ans = "";
       // cout<<cb<<" "<<ob<<" ";
        for(int i=0;i<n;i++)
        {
          if(s[i] == '*') continue;
            else ans +=s[i];
        }
        return ans;
    }
};