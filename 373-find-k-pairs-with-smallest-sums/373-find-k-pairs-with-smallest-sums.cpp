class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> pq;
        int n1=nums1.size(),n2=nums2.size(); 
        for(int i=0;i<n1&&i<k;i++)
        {
            pq.push({nums2[0]+nums1[i],{nums1[i],{nums2[0],0}}});
        }
        vector<vector<int>> ans;
        while(k&&!pq.empty())
        {
            //vector<int> res;
            ans.push_back({pq.top().second.first,pq.top().second.second.first});
            int idx = pq.top().second.second.second,el=pq.top().second.first;
            
            pq.pop();
            
            if(idx != n2-1)
            {
                pq.push({el+nums2[idx+1],{el,{nums2[idx+1],idx+1}}});
            }
            k--;
        }
    return ans;
    }
};