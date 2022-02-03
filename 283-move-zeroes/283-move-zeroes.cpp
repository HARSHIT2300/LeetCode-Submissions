class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct=INT_MAX,i=0;
        for(auto &el : nums)
        {
            if(el) 
            {
                if(ct<i)
                {
                    nums[ct]=el;
                    nums[i]=0;
                    ct++;
                }
            }
            else
            {
                if(ct==INT_MAX) ct=i;
            }
            i++;
        }
     
    }
};