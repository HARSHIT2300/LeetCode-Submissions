class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> ans; ans=prices;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && prices[i]<=prices[st.top()])
            {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;   
    }
};