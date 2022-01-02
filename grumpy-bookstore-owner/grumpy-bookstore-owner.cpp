class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0,sm=0,mx=0; 
        for(int i=0;i<customers.size();i++)
        {
            if(!grumpy[i])
            {
                ans+=customers[i]; 
                  if(i>=minutes-1)
            {
                if(grumpy[i-minutes+1])
                sm-=customers[i-minutes+1];
            }
                continue;
            }
             sm+=customers[i];
              mx=max(sm,mx);;
            cout<<sm<<" ";
            if(i>=minutes-1)
            {
                if(grumpy[i-minutes+1])
                sm-=customers[i-minutes+1];
            }
        }
        
        return ans+mx;
    }
};