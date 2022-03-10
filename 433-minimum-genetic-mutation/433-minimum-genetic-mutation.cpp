class Solution {
public:
    bool diff(string s,string s1)
    {   int dif=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s1[i]) dif++;
            if(dif>1) return false;
        }
     return true;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string,int> vis;
        //memset(vis,false,sizeof(vis));
        vis[start] = 1;
        queue<pair<string,int>> q;
        q.push({start,0});
        while(!q.empty())
        {   string node = q.front().first;
            int d = q.front().second;
            q.pop();
         for(int i=0;i<n;i++)
         {
             if(!vis[bank[i]] && diff(node,bank[i]))
             {
                 vis[bank[i]]=1;
                 q.push({bank[i],d+1});
                 if(bank[i] == end) return d+1;
             }
         }
        }
        return -1;
    }
};