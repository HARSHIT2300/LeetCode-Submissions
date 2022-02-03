class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct=0;
        for(auto &el : nums)
        {
            if(el) ct++;
        }
        int l=0,i=0;
        while(l<ct)
        {
            if(nums[i]){
                nums[l]=nums[i]; l++;}
            i++;
        }
        i=ct;
        int n=nums.size();
        while(i<n)
        {
            nums[i]=0; i++;
        }
    }
};