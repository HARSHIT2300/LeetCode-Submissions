class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
       vector<int> nge(n,n),nle(n,n),pge(n,-1),ple(n,-1);
        stack<int> st1,st2,st3,st4;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && nums[st1.top()] <= nums[i]){
                nge[st1.top()] = i; st1.pop();}
             while(!st2.empty() && nums[st2.top()] >= nums[i]){
                nle[st2.top()] = i; st2.pop();}
            st1.push(i); st2.push(i);
        }
        for(int i=n-1;i>=0; i--)
        {
             while(!st3.empty() && nums[st3.top()] < nums[i]){
                pge[st3.top()] = i; st3.pop();}
             while(!st4.empty() && nums[st4.top()] > nums[i]){
                ple[st4.top()] = i; st4.pop();}
            st3.push(i); st4.push(i);
        }
        long long ans =0;
       
        for(int i=0;i<n;i++)
        {
            
            ans +=(((long long)(nge[i]-i)*(long long)(i-pge[i]))*nums[i]);
             cout<<ans<<" ";
            ans -=(((long long)(nle[i]-i)*(long long)(i-ple[i]))*nums[i]);
            cout<<ans<<"\n";
         
        }
        return ans;
    }
};