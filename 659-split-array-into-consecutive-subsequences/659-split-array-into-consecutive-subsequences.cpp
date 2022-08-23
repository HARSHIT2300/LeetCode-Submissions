class Solution {
public:
    bool isPossible(vector<int>& nums) {
       map<int,int> count;
        for(auto &el : nums)
        {
            count[el]++;
        }
        int cnt = 0;
        map<int,int> mp;
        map<int,int> cons;
        for(int i=0;i<nums.size();i++)
        {
       //     if(cons[i]) continue;
         //   cons[i]+=1;
           
            auto el = nums[i];
             if(count[el] == 0)continue;
            if(!mp[el])
            {
                if(count[el+1] && count[el+2])
                {   count[el]--;
                    count[el+1]--;
                    count[el+2]--;
                    mp[el+3]++;
                }
                else return false;
            }
            else
            {
                if(count[el]) {count[el]--;mp[el]--; mp[el+1]++;}
            }
        }
        return  true;
    }
};