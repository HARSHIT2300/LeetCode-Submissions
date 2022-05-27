class Solution {
public:
    string longestPalindrome(string s) {
        // errichto's approach
        int n = s.size();
        int dp[n][n];
       
        int res_size = 1;
        int start = 0;
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            if(i<n-1 && s[i] == s[i+1])
                dp[i][i+1] = 1;
        }
        for(int pos = 0; pos<n; pos++)
        {
            int low = pos-1, high  = pos+1;
            while(low<=high && low>=0 && high<n)
            {
                if(s[low] != s[high]) break;
                if(high-low+1>res_size)
                {
                    start = low;
                    res_size = high-low+1;
                }
                low--; high++;
            }
            low = pos, high = pos+1;
             while(low<high && low>=0 && high<n)
            {
                if(s[low] != s[high]) break;
                if(high-low+1>res_size)
                {
                    start = low;
                    res_size = high-low+1;
                }
                low--; high++;
            }
        }
        return s.substr(start,res_size);
    }
};