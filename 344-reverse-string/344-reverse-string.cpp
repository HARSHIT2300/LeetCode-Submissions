class Solution {
public:
    void reverseString(vector<char>& s) {
       int l=0,r=s.size()-1;
        char ch;
        while(l<r)
        {
            ch = s[l];
            s[l] = s[r];
            s[r] = ch;
            l++; r--;
        }
    }
};