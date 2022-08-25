class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        int ans = sum;
        for(int j=1;j<=k;j++)
        {
            sum+=cardPoints[cardPoints.size()-j];
            sum-=cardPoints[k-j];
            ans=max(ans,sum);
        }
        return ans;
    }
};