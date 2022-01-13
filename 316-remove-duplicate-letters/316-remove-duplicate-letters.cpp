class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool vis[26];
        memset(vis,false,sizeof(vis));
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        string ans="";
        stack<char> st;
        for(auto &el : s) cnt[el - 'a']++;
        for(auto &el : s)
        {
            int ch = el - 'a';
            cnt[ch]--;
            if(vis[ch]) continue;
            while(!st.empty() && el < st.top() && cnt[st.top()-'a']!=0 )
            {
                vis[st.top()-'a'] = false; st.pop();
            }
            st.push(el);
            vis[ch] = true;
        }
      
        while(!st.empty())
        {
            ans = st.top() + ans; st.pop();
        }
        return ans;
    }
};