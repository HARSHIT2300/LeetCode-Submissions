class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0; int n =points.size();
        bool vis[n]; 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<n;i++)
        {
            pq.push({abs(points[0][0]-points[i][0])+abs(points[0][1]-points[i][1]),i});
        }
        int edges=0;
        vis[0]=1;
        while(edges!=n-1)
        {
            while(vis[pq.top().second])
                pq.pop();
            int idx = pq.top().second;
            ans+=pq.top().first;
            vis[idx] =1;
            edges++;
            pq.pop();
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    pq.push({abs(points[idx][0]-points[i][0])+abs(points[idx][1]-points[i][1]),i});
                }
            }
        }
        return ans;
    }
};