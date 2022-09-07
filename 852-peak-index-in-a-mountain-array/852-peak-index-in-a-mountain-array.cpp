class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1,r = arr.size()-2,ans;
        while(l <= r)
        {
            int mid = l + ((r-l)>>1);
           
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            {
                ans = mid; break;
            }
           // 0 5 1 2 3
            else if(arr[mid+1] > arr[mid]) l =mid+1;
            else  r = mid-1;
        }
        return ans;
    }
};