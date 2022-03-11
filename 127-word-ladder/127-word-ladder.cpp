class Solution {
public:
    bool diff(string  &s,string &s1)
    {
        int n = s.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s1[i]) ans++;
            if(ans>1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> vis,mp,mp1,vis1;
        int n = wordList.size();
        for(auto &el : wordList)
        {
            mp[el]=1;
        }
        if(!mp[endWord]) return 0;
        if(!mp[beginWord]){
            n+=1;
            wordList.push_back(beginWord);
            mp[beginWord]=1;
        }
        unordered_map<string,vector<string>> adj;
        for(auto &el : wordList)
        {
             int n1 = el.size();
            for(int i=0;i<n1;i++)
            {   string s = el;
                for(char ch = 'a';ch<='z';ch++)
                {
                    s[i] =ch;
                    if(mp[s])
                    {
                        adj[el].push_back(s);
                        adj[s].push_back(el);
                    }
                }
            }
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1}); vis[beginWord]=1;
        while(!q.empty())
        {
            string node = q.front().first; int d = q.front().second;
         
            q.pop();
          //  cout<<node<<" ";
            for(auto &child : adj[node])
            {
                if(!vis[child])
                {   
                    if(child == endWord)
                    return d+1;
                    q.push({child,d+1});
                    vis[child]=1;
                }
            }
        }
        return 0;
    }
};