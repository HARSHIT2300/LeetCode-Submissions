class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int idx=0;
        for(auto &el : points)
        {
            pq.push({-((el[0]*el[0])+(el[1]*el[1])),idx});
            idx++;
        }
        vector<vector<int>> ans;
        
        while(k--)
        {   idx = pq.top().second;
         vector<int> v; 
         v.push_back(points[idx][0]);
         v.push_back(points[idx][1]);
            ans.push_back(v);
         pq.pop();
        }
        return ans;
    }
};