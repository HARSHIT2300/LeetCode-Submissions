class Solution {
public:
    long long numberOfWays(string s) {
        vector<long long> v;
        int ct=1;
        int n = s.length();
        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1])
            {
                ct++;
            }
            else
            {
                v.push_back(ct);
                ct=1;
            }
        }
        
        v.push_back(ct);
        long long ps1=0,ps0=0;
        int n1= v.size();
        vector<long long> pse(n1,0),pso(n1,0),rse(n1,0),rso(n1,0);
        for(int i=0;i<n1;i++)
        {
            if(i%2)
            {   ps1+=v[i];
                pso[i] = ps1;
                
            }
            else
            {   ps0+=v[i];
                pse[i] = ps0;
                
            }
        }
        // cout<<ps1<<" "<<ps0<<" ";
        ps1=0,ps0=0;
        for(int i=n1-1;i>=0;i--)
        {
            if(i%2)
            {   ps1+=v[i];
                rso[i] = ps1;
                
            }
            else
            {    ps0+=v[i];
                rse[i] = ps0;
               
            }
        }
        long long ans=0;
        // for(int i=0;i<n1;i++) cout<<pse[i]<<" "<<pso[i]<<"\n";
        // for(auto &el : v) cout<<el<<" ";
        for(int i=1;i<v.size()-1;i++)
        {
           if(i%2)
           {
            ans+=(rse[i+1]*v[i]*pse[i-1]);   
           }
            else
            {
                ans+=(rso[i+1]*v[i]*pso[i-1]); 
            }
        }
        return ans;
    }
};