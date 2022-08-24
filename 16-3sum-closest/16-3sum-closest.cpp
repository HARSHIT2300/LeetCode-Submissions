class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;
        sort(nums.begin(),nums.end());
        int ans ;
        for(int i=0;i<nums.size();i++)
        {
            //int t_sum = target - nums[i];
            int low = i+1,high = nums.size()-1;
            while(low < high)
            {
                int c_sum =  nums[low] + nums[high] + nums[i];
                 
                if(abs(target- c_sum) < min)
                { 
                    min = abs(target - c_sum);
                    ans = c_sum;
                }
                while(low < high && nums[low] == nums[low+1])
                {
                    low++;
                }
                while(low < high && nums[high] == nums[high-1])
                {
                    high--;
                }
                if(c_sum < target) low++;
                else high--;
            }
        }
        return ans;
    }
};