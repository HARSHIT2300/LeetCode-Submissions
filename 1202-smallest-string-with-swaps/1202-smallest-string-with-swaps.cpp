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
    // standard union find code of disjoint set data structure
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
        // Initially, each index is treated as a unique component
        // We Union the indices that are provided as pairs in the input beacuse it means now they will now belong to the same component.
        unordered_map<int,string> par_str;
        // par_str will store all those chars as  a string which belong to the same component and the key will be the root Parent of each component. This is implemented in the loop Below 
        unordered_map<int,int> idx_str;
        // idx_str will store the index upto which the characters of the string stored as value in par_str have been already computed....
        for(int i=0;i<n;i++)
        {
            int p = findPar(i);
            par_str[p].push_back(s[i]);
        }
        for(auto &el : par_str)
        {
            sort(el.second.begin(),el.second.end());
        }
        // Sorting the string as we want increasing order
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