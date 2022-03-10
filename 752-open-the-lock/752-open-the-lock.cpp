class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
       // int tg = stoi(target);
        unordered_map<string,int> dead,vis;
        if(target == "0000") return 0;
//  memset(vis,false,sizeof(vis));
        for(auto &el : deadends)
        {
            dead[el]=1;
            if(el == "0000") return -1;
        }
        queue<pair<string,int>> q;
        q.push({"0000",0}); vis["0000"]=1;
        while(!q.empty())
        {
            string node = q.front().first;
            int d = q.front().second; q.pop();
          //  cout<<node<<" ";
            for(int i=0;i<4;i++)
            {
                string child = node;
               
                     int a = int(child[i]); a-=48;
                    a+=1; a%=10; a+=48;
                    child[i] = (char)a;
                    if(child == target) return d+1;
                    if(!dead[child]&&!vis[child]){
                        q.push({child,d+1}); vis[child] =1;}
                    child = node;
                    a = int(child[i]); a-=48;
                    a+=9; a%=10; a+=48;
                    child[i] = (char)a;
                    if(!dead[child] && !vis[child])
                    {
                          q.push({child,d+1}); vis[child] =1;
                    }
                     if(child == target) return d+1;
                    
                
            }
        }
        return -1;
    }
};