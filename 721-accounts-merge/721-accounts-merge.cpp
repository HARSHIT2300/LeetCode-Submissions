class Solution {
public:
    // considering each Account  as a component.  Two Accounts are merged/unioned when there is some common email(provided that they both aren't already connected)
    vector<int> par,rank;
    void unionn(int a,int b)
    {
        a = findPar(a); b = findPar(b);
        if(a == b) return ;
        if(rank[a]<rank[b]) par[a] = b;
        else if(rank[b]<rank[a]) par[b] = a;
        else 
        {
            par[a] =b; rank[b]++;
        }
    }
    int findPar(int n)
    {
        if(par[n] == n) return n;
        return par[n] = findPar(par[n]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,int> par_str;
        // Store the Account Name of each email 
    int n = accounts.size();
    for(int i=0;i<n;i++)
    {
        rank.push_back(0); par.push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<accounts[i].size();j++)
        {
        
            if(par_str.count(accounts[i][j]))
            {
                // if the email is encountered earlier, which means the component of that email,par_str[accounts[i][j]] ;  and the present component , i ; will be unioned/merged into a single component
                unionn(i,par_str[accounts[i][j]]);
            }
            else
                par_str[accounts[i][j]] =i;
            // if the email is not encountered earlier we assign the value of it's component
        }
    }

        unordered_map<int,vector<string>> mp;
    for(auto &el  : par_str)
    {
        int p = findPar(el.second);
        // finding the root  Parent  of the Component
        mp[p].push_back(el.first);
        // pushing the email corresponding to it's root Parent....
    }
        vector<vector<string>> ans;
    for(auto &el : mp)
    {
        vector<string> v = el.second;
        sort(v.begin(),v.end());
        v.insert(v.begin(),accounts[el.first][0]);
        // inserting the Account Holder's Name
        ans.push_back(v);
    }
        return ans;
    }
};