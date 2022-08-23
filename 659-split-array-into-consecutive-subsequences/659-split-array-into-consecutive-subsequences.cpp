class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> v(10003,0);
        int l_idx=0;
        map<int,set<int>> mp;
        v[0]=1; mp[nums[0]].insert(0);
        int tot = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(mp[nums[i]-1].size() == 0)
            {
                ++l_idx;
                v[l_idx]+=1;
                mp[nums[i]].insert(l_idx);
            }
            else
            {
                set<int> s = mp[nums[i]-1];
                int id = *(s.begin());
                int mn = v[id];
                for(auto &el : s)
                {
                    if(v[el] <= mn)
                    {
                        mn = v[el];
                        id = el;
                    }
                }
                mp[nums[i]].insert(id);
                v[id]+=1;
                if(v[id] == 3) tot++;
                mp[nums[i]-1].erase(mp[nums[i]-1].find(id));
            }
        }
      //  cout<<tot<<" "<<l_idx<<" ";
       return tot-1 == l_idx;
        //return true;
    }
};