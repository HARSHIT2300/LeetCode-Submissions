class Solution {
public:
    vector<int> rank,par;
    int findPar(int n1)
    {
        if(par[n1] == n1) return n1;
        return par[n1] = findPar(par[n1]);
    }
    void unionn(int a,int b)
    {   a = findPar(a); b =findPar(b);
       if(a == b) return ;
     if(rank[a] < rank[b])
         par[a] = b;
     else if(rank[b] < rank[a])
         par[b] = a;
     else
     {
         par[a] = b;
         rank[a]++;
     }
    }
    bool equationsPossible(vector<string>& equations) {
       
        for(int i = 0;i<=122;i++)
        {
            par.push_back(i); rank.push_back(0);
        }
        for(auto &eq : equations)
        { 
            if(eq[1] == '=')
            {
                
                unionn(eq[0],eq[3]);   
            } 
        }
        
        for(auto &eq : equations)
        {
            if(eq[1] == '!' && findPar(eq[0]) == findPar(eq[3]))
                return false;
        }
        return true;
        
    }
};