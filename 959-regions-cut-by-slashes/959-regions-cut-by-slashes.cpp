class Solution {
public:
    vector<int> par,rank;
    int ans,n;
    int isPar(int n1)
    {
        if(par[n1]==n1) return n1;
          par[n1]=isPar(par[n1]);
        return par[n1];
    }
    void unionn(int a,int b)
    {
        a = isPar(a); b = isPar(b);
        if(a == b) return;
        ans--;
        if(rank[a]<rank[b])
            par[a]=b;
        else if(rank[b]<rank[a])
            par[b]=a;
        else {
            par[b]=a; rank[a]+=1;}
    }
    int gph(int x,int y,int z)
    {
        return ((x*n + y) *4) + z ;  //considering each unit(out of 4 units) of each grid as a node of graph
    }
    int regionsBySlashes(vector<string>& grid) {
        
        n = grid.size();
         ans = n*n*4;
        
        for(int i=0;i<n*n*4;i++) {par.push_back(i); rank.push_back(0);}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i)
                unionn(gph(i-1,j,2),gph(i,j,0));
                if(j)
                 unionn(gph(i,j-1,1),gph(i,j,3));  
               if(grid[i][j] == '/')
               {
                   unionn(gph(i,j,1),gph(i,j,2));
                   unionn(gph(i,j,0),gph(i,j,3));
               }
               else if(grid[i][j] == '\\')
                {
                   unionn(gph(i,j,3),gph(i,j,2));
                   unionn(gph(i,j,0),gph(i,j,1));
                }
                else
                {
                  unionn(gph(i,j,0),gph(i,j,1));
                   unionn(gph(i,j,1),gph(i,j,2));
                    unionn(gph(i,j,2),gph(i,j,3));
                    unionn(gph(i,j,3),gph(i,j,0));
                }
            }
        }
        return ans;
    }
};