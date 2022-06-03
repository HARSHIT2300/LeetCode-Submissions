class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int max_no_del = arr[0];
        int max_del = 0;
        int ans = arr[0];
        for(int i = 1;i<arr.size();i++)
        {
             max_del = max(max_del+arr[i],max_no_del);
            max_no_del = max(arr[i],arr[i] + max_no_del);
           ans = max({ans,max_no_del,max_del});
        }
        return ans;
    }
};