class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> st;
        int ans = 0;
        int sz = nums.size();
        vector<int> ll(sz,0),rl(sz,0);
        for(int i=0; i < sz; i++)
        {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            ll[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        stack<int> st1;
        for(int i = sz-1;i>=0;i--)
        {
            while(!st1.empty() && nums[i] <= nums[st1.top()])
                st1.pop();
            rl[i] = st1.empty() ? sz-1 : st1.top()-1;
            if(ll[i]<=k && rl[i]>=k) ans = max(ans, (rl[i] - ll[i] +1)*nums[i]);
         //   cout<<ll[i]<<" "<<rl[i]<<"\n";
            st1.push(i);
        }
        return ans;
    }
};