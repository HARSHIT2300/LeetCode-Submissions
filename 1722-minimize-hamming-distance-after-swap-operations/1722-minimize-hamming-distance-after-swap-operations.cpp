class Solution {
public:
    vector<int> par,rank;
    int findPar(int n1)
    {
        if(par[n1] == n1) return n1;
        return par[n1] = findPar(par[n1]);
    }
    void unionn(int a,int b)
    {
        a =  findPar(par[a]);
        b = findPar(par[b]);
        if(a == b) return ;
        if(rank[a] < rank[b]) par[a] = b;
        else if(rank[b] < rank[a]) par[b] = a;
        else {
            par[a] = b;
            rank[b] +=1;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        for(int i=0;i<n;i++)
        {
           par.push_back(i);
        rank.push_back(0);
        }
      
       for(auto &v : allowedSwaps)
       {
           unionn(v[0],v[1]);
         
       }
      map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++)
        {
           findPar(i);
            mp[{par[i],source[i]}]++;
             mp[{par[i],target[i]}]--;
        }
         int ans = 0;
        for(auto &p : mp)
        {
            // cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<"\n";
         if(p.second > 0)
             ans+=p.second;
        }
        return ans;
    }
};