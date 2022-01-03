class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int ans = 0;
      int last_ct = 0,cmax=0;
     //   aaaabbbbbc
        int a=0,b=0;
        for(auto &el : fruits)
        {
            if(b == el)
            {
                last_ct ++;
                    cmax ++;
            }
            else if(a == el)
            {
                last_ct = 1;
                cmax++;
                a = b; b = el;
            }
            else
            {
                cmax = last_ct+1;
                last_ct=1;
                a = b; b = el;
            }
            ans = max(ans,cmax);
        }
        return ans;
    }
};