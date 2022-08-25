class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        vector<int> lf(heights.size(),0),rf(heights.size(),0);
        for(int i=0;i<heights.size();i++)
        {
         while(!st.empty() && heights[st.top()] >= heights[i])
         {
             st.pop();
         }
            if(st.empty()) lf[i] = 0;
            else lf[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
   //     int ans = 0;
         for(int i=heights.size()-1;i>=0;i--)
        {
         while(!st.empty() && heights[st.top()] >= heights[i])
         {
             st.pop();
         }
            if(st.empty()) rf[i] = heights.size()-1;
            else rf[i] = st.top()-1;
            st.push(i);
             ans = max(ans, (rf[i] - lf[i] +1 )*heights[i]);
        }
        // for(int i=0;i<heights.size();i++)
        // {
        //     cout<<lf[i]<<" "<<rf[i]<<"\n";
        // }
        return ans;
    }
};