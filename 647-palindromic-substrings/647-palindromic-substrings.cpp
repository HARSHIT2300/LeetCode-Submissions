class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for(int ps=0;ps<n;ps++)
        {
            int low = ps-1,high = ps+1;
            while(low>=0 && high<n)
            {
                if(s[low] != s[high]) break;
                ans++;
                low--; high++;
            }
            low = ps,high = ps+1;
            while(low>=0 && high<n)
            {
                if(s[low] != s[high]) break;
                ans++;
                low--; high++;
            }
        }
        return ans;
    }
};