class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st1,st2;
        int n = arr.size();
        vector<int> nse(n,n),pse(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && arr[st1.top()] >= arr[i] )
            {
                nse[st1.top()] = i; st1.pop();
            }
            st1.push(i);
        }
         for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() && arr[st2.top()] > arr[i] )
            {
                pse[st2.top()] = i; st2.pop();
            }
             st2.push(i);
        }
        long long  ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += ((long long)arr[i]*(nse[i]-i)*(i-pse[i]));
            ans%=1000000007;
        }
       // int res = (int)ans;
        return (int)ans;
    }
};