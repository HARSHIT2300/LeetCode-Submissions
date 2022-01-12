class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int n = s.length(); int ans =0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '[') st.push(i);
            else
            {
                if(st.empty()) ans++;
                else st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};