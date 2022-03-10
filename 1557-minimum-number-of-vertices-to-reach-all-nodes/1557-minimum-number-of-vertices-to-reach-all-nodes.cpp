class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      //  int n=edges.size();
       int in[n];
        memset(in,0,sizeof(in));
        for(auto &edge : edges)
        {
            in[edge[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]) continue;
            ans.push_back(i);
        }
        return ans;
    }
};