class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // need to find maximum no of non overlapping intervals and then subtract it from total no of intervals.  It will give us minimum intervals reqd to make the intervals non overlapping
        sort(intervals.begin(),intervals.end(),cmp);
        int end_pt=intervals[0][1];
        int ct_non_overlap_inter=1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=end_pt)
            {
                end_pt=intervals[i][1];
                ct_non_overlap_inter+=1;
            }
        }
        return intervals.size()-ct_non_overlap_inter;
    }
};