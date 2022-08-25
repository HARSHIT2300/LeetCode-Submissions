class Solution {
public:
  
    int subarraysDivByK(vector<int>& nums, int k) {
       int psum=0;
        map<int,int> mp;
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
           psum+=nums[i];
           int a =psum%k;
            if(a < 0) a+=k;
            ans+=mp[a];
            mp[a]++;
        }
        return ans;
    }
};