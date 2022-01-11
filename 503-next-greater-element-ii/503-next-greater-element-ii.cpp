class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(nums.size(),-1);
       for(int i=0,j=0;j<n*2;i++,j++)
       {    i%=n;
           while(!st.empty() && nums[st.top()] < nums[i]){ ans[st.top()] = nums[i]; 
            st.pop();}
           st.push(i);
          // if(ans[0] != -1 && ans[0] != nums[i])
       }
        return ans;
    }
};