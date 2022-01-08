class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int i=0,j=0,sm=0;
       
        deque<int> dq;
        int n = nums.size();  int ans = n+1;
         long prefix[n];
        while(j<n)
        {
           if(j) prefix[j]=nums[j]+prefix[j-1];
            else prefix[j]=nums[j];
            if(prefix[j]>=k) ans = min(ans,j+1);
            while(dq.size() && prefix[dq.back()]>prefix[j]) dq.pop_back();
         //   cout<<prefix[j]<<" ";for(auto el : dq) cout<<el<<" "; cout<<"\n";
            while(dq.size() && prefix[j]-prefix[dq.front()] >= k){
                ans = min(ans,j-dq.front()); dq.pop_front();}
         //    cout<<dq.size()<<" "<<j<<"\n";
                dq.push_back(j); j++;
        }
      return ans == n+1 ? -1 : ans;
    }
};