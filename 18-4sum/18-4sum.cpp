class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size(); )
        {   v.push_back(nums[i]);
            for(int j = i+1; j<nums.size(); )
            {   v.push_back(nums[j]);
                int low = j+1,high = nums.size()-1;
                while(low < high)
                {   
                   long long int sum = 0LL +nums[low]+nums[high]+nums[i]+nums[j] ;
                    int lf = 0, rf = 0;
                    if(sum == target)
                    {
                        v.push_back(nums[low]);
                        v.push_back(nums[high]);
                        ans.push_back(v);
                        v.pop_back(); v.pop_back();
                       lf = 1,rf=1;
                    }
                 
                 else if(sum < target) lf+=1;
                 else rf = 1;
                //  cout<<i<<j<<low<<high<<" ";
                 if(lf)
                 {
                     while(low < high && nums[low] == nums[low+1])
                     low++;
                     low+=1;
                 }
                 if(rf)
                 {
                    
                    while(low < high && nums[high] == nums[high-1])
                     high--; 
                     high--;
                 }
                              
                }
            
              while(j < nums.size()-2 && nums[j] == nums[j+1])
                     j++;
              ++j;
             v.pop_back();
            }
        
         while(i < nums.size()-3 && nums[i] == nums[i+1])
                     i++;
          ++i;
         v.pop_back();
        }
        return ans;
    }
    
};