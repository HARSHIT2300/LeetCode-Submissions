class Solution {
public:
    vector<int> par,rank;
    void unionn(int a,int b)
    {
        a = findPar(a); b = findPar(b);
        if(a == b) return ;
        if(rank[a]<rank[b]) par[a] = b;
        else if(rank[b]<rank[a]) par[b] = a;
        else
        {
            par[a] = b;
            rank[b]++;
        }
    }
    int findPar(int n)
    {
        if(par[n] == n) return n;
        return par[n] = findPar(par[n]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n  = s.size();
        for(int i=0;i<n;i++) {
            par.push_back(i);
            rank.push_back(0);
        }
        for(auto &p : pairs)
        {
            unionn(p[0],p[1]);
        }
        unordered_map<int,string> par_str;
        unordered_map<int,int> idx_str;
        for(int i=0;i<n;i++)
        {
            int p = findPar(i);
            par_str[p].push_back(s[i]);
        }
        for(auto &el : par_str)
        {
            sort(el.second.begin(),el.second.end());
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            int p  = findPar(i);
            ans+=par_str[p][idx_str[p]];
            idx_str[p]++;
        }
        return ans;
    }
};