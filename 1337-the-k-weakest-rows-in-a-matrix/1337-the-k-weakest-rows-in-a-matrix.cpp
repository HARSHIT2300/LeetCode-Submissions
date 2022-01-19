class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int ct,idx=0;
        for(auto &v : mat)
        {   ct=0;
            for(auto &el : v)
            {
                if(el) ct++;
                else break;
            }
         pq.push({-ct,-idx});
         idx++;
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        return ans;
    }
};