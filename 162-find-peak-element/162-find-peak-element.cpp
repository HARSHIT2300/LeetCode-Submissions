class Solution {
public:
   
    int findPeakElement(vector<int>& nums) {
      int l = 1,r = nums.size()-1,ans;
        if(nums.size() == 1) return 0;
      if(nums[0] > nums[1]) return 0;
      if(nums[r] > nums[r-1]) return r;
        r-=1;
      while(l<=r)
      {
          int mid = l + ((r-l)>>1);
          if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
          {
              ans = mid;
              break;
          }
          else if(nums[mid] < nums[mid-1]) r = mid-1;
          else l = mid+1;
      }
        return ans;
    }
};