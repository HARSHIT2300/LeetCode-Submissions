class Solution {
public:
    void merge(int l,int md,int r,vector<int> &nums)
    {
        int l1=l,l2=md+1;
        vector<int> v;
        while(l1<=md&&l2<=r)
        {
            if(nums[l1]<=nums[l2])
            {
                v.push_back(nums[l1]);
                ++l1;
            }
            else
            {
                 v.push_back(nums[l2]);
                ++l2;
            }
        }
        while(l1<=md)
        {
             v.push_back(nums[l1]);
                ++l1;
        }
        while(l2<=r)
        {
              v.push_back(nums[l2]);
                ++l2;
        }
        
        for(auto &el : v)
        {
          
            nums[l]=el; ++l;
        }
    }
    void merge_sort(int l,int r,vector<int> &nums)
    {
        if(l<r)
        {
            int mid = l+((r-l)>>1);
            merge_sort(l,mid,nums);
            merge_sort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(0,nums.size()-1,nums);
        return nums;
    }
};