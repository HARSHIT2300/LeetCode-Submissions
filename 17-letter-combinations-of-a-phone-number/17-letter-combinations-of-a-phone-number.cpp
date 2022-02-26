class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        stack<string> st;
        st.push("");
        vector<string> ans;
        while(!st.empty())
        {
            string res = st.top();
              st.pop();
            if(res.size() == digits.size()){if(res.size()) ans.push_back(res); continue;}
            int ch = digits[res.size()]-50;
            for(auto ch1 : v[ch])
            {
                st.push(res+ch1);
            }
          
        }
        return ans;
    }
};