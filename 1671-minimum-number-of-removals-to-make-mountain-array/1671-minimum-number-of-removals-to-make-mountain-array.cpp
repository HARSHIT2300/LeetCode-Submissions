class Solution {
public:
   // void calc(int i,vector<int> &nums,vector<int> &inc_seq)
    int minimumMountainRemovals(vector<int>& nums) {
        // bitonic array
        vector<int> inc_seq;
        int n = nums.size();
        vector<int> l_inc(n,1),r_inc(n,1);
        for(int i = 0; i< n ; i++)
        {
           auto it = lower_bound(inc_seq.begin(),inc_seq.end(),nums[i]);
            if(it == inc_seq.end())
                inc_seq.push_back(nums[i]);
            else
            {
                *it = nums[i];
            }
            l_inc[i] = inc_seq.size();
        }
        inc_seq.clear();
      //  cout<<inc_seq.size()<<" ";
        for(int i = n-1; i >=0 ; i--)
        {
           auto it = lower_bound(inc_seq.begin(),inc_seq.end(),nums[i]);
            if(it == inc_seq.end())
                inc_seq.push_back(nums[i]);
            else
            {
                *it = nums[i];
            }
            r_inc[i] = inc_seq.size();
        }
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {  // cout<<l_inc[i]<<" "<<r_inc[i]<<"\n";
            if(l_inc[i]>1 && r_inc[i] > 1)
            ans = max(ans,l_inc[i]+r_inc[i]-1);
        }
        return n-ans;
    }
};