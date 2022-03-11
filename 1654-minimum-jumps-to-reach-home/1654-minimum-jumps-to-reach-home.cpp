class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,pair<int,int>>> q;
        if(x ==0 ) return x;
        q.push({0,{0,0}});
        bool forbid[100001];
        memset(forbid,false,sizeof(forbid));
        for(auto &el : forbidden)
            forbid[el] =true;
        bool vis[2][100001];
        memset(vis,false,sizeof(vis));
        vis[0][0] = true;
        while(!q.empty())
        {
            int node = q.front().first,col = q.front().second.first,d=q.front().second.second; q.pop();
            int a1 = node+a;
        
           cout<<node<<" ";
            if(a1>=0 && !forbid[a1] &&  !vis[0][a1] && a1<=10000)
            {
              //  if(a1<x|| (a1>x && a1-b>=x))
                q.push({a1,{0,d+1}});
                if(a1 == x) { return d+1;}
                vis[0][a1]=1;
            }
            if(!col){
           a1 = node-b;
            if( a1>=0 && !forbid[a1] && !vis[1][a1] )
            {
                if(a1 == x){
                 //   cout<<node<<" "; 
                    return d+1;}
                q.push({a1,{1,d+1}});
                vis[1][a1]=1;
            }
            }
        }
        return -1;
    }
};