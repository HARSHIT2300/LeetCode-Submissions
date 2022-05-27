class Solution {
public:
    string longestPalindrome(string s) {
        // errichto's approach
        //even length and odd length strings are possible and considering the initial position we then radiate  low and high in opposite directions... more intuitive + easy to think + doesn't use up extra space 
        int n = s.size();
       
       
        int res_size = 1;
        int start = 0;

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