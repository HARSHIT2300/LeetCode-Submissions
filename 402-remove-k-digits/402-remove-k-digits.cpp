class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k) return "0";
        stack<char> st;
        int n = num.size();
        st.push(num[0]);
       for(int i=1;i<n;i++)
        {
            while(!st.empty()&&k&&(int)num[i]<(int)st.top())
            {
                st.pop(); k--;
            }
           st.push(num[i]);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans; st.pop();
        }
        if(k) {
            ans = ans.substr(0,ans.size()-k);
        }
       k=-1;
        for(int i=0;i<ans.size()&&ans[i]=='0';i++)
        {
            k=i+1;
        }
        if(k>-1)
         ans = ans.substr(k,ans.size()-k);
        if(ans.size() == 0) ans="0";
            return ans;
    }
};