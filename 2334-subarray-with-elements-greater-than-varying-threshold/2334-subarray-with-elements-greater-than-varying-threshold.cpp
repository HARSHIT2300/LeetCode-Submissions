class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        // 1, 3, 4, 3, 1
        if(threshold < nums.size())return nums.size(); 
      //  mn = 3  6/3 = 2      mn = 2    6 / (4= thres / )     mn = 3   6 /3
        stack<int> st;
        int sz = nums.size();
        vector<int> lf(sz,0),rf(sz,0);
        for(int i=0; i < sz; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            lf[i] = st.empty() ? 0 : st.top()+1;
            st.push(i);
        }
        stack<int> st1;
        for(int i = sz-1 ; i>=0; i--)
        {
            while(!st1.empty() && nums[st1.top()] >= nums[i])
                st1.pop();
            rf[i] = st1.empty() ? sz-1 : st1.top()-1;
            int reqd_range = threshold / nums[i] ; reqd_range+=1;
            if(rf[i] - lf[i]+1 >= reqd_range) return rf[i]-lf[i]+1;
            st1.push(i);
        }
    return -1;
    }
};