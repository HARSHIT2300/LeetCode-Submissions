class Solution {
public:
    vector<int> par,rank;
    bool unionn(int a,int b)
    {
        a = findPar(a); b = findPar(b);
        if(a == b) return true;
        if(rank[a]<rank[b])
            par[a]=b;
        else if(rank[b]<rank[a])
            par[b]=a;
        else
        {
            par[a]=b;
            rank[b]++;
        }
        
        return false;
    }
    int findPar(int n)
    {
        if(par[n] == n) return n;
        return par[n] = findPar(par[n]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i=0;i<n;i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
        vector<int> ans;
        for(auto &edge : edges){
            if(unionn(edge[0]-1,edge[1]-1)){
                ans.push_back(edge[0]); 
                ans.push_back(edge[1]);
                return ans;}
        }
       return ans; 
    }
};