bool cmp(vector<int>& v1,vector<int>& v2)
{
   
    return v1[1] < v2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end(),cmp);
        int ed = intervals[0][1];
        int ans = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] < ed) ans++;
            else ed = intervals[i][1];
        }
        return ans;
    }
};