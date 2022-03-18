class Solution {
public:
    vector<int> par,rank;
    void unionn(int a,int b)
    {
        a = findPar(a); b=findPar(b);
        if(a == b) return;
        if(rank[a]<rank[b]) par[a]=b;
        else if(rank[b]<rank[a]) par[b]=a;
        else
        {
            par[a]=b; rank[b]++;
        }
    }
    int findPar(int n)
    {
        if(par[n] == n) return n;
        return par[n] = findPar(par[n]);
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<m*n;i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
        int ct_servers=0;
        for(int i=0;i<m;i++)
        {   int pidx=-1;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {   cout<<"1"<<" ";
                    ct_servers++;
                    if(pidx != -1)
                        unionn(pidx,n*i+j);
                     pidx = n*i+j;
                }
            }
        }
         for(int i=0;i<n;i++)
        {   int pidx=-1;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i])
                {   //cout<<"1"<<" ";
                   // ct_servers++;
                    if(pidx != -1)
                        unionn(pidx,n*j+i);
                     pidx = n*j+i;
                }
            }
        }
     //   cout<<ct_servers<<" ";
        for(int i=0;i<m*n;i++)
        {
            if(grid[i/n][i%n]&& par[i] == i && !rank[i]) ct_servers--;
        }
        return ct_servers;
    }
};