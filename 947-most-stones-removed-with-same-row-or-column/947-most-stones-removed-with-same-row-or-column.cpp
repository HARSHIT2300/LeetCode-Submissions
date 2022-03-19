class Solution {
public:
    // stones will connect the specific row no and col no
    // row no 0-10000    col no 10001 - 20001
    // the different row nos and col nos 
   
    vector<int> par,rank;
     int components;
    void unionn(int a,int b)
    {
        a = findPar(a); b = findPar(b);
        if(a == b) return ;
        components--;
        // decrease in total number of components by 1 as 2 components will be merged into 1
        if(rank[a]<rank[b]) par[a] = b;
        else if(rank[b]<rank[a])  par[b] = a;
        else
        {
            par[a]=b;
            rank[a]++;
        }
        
    }
    int findPar(int n1)
    {
        if(par[n1] == -1) 
            par[n1] = n1,components++;
        // each row no and col no that hasn't been coonsidered yet, will act as a single component initially
        if(par[n1] == n1) return n1;
        return par[n1] = findPar(par[n1]);
    }
    int removeStones(vector<vector<int>>& stones) {
        components = 0;
        for(int i=0;i<=20001;i++) par.push_back(-1),rank.push_back(0);
        for(auto &v : stones)
        {
           unionn(v[0],10001+v[1]); 
        }
        return stones.size()-components;
    }
};