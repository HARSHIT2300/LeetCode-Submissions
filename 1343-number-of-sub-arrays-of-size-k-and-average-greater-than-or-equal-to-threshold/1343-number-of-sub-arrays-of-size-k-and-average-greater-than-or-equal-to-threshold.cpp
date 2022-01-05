class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int r=0,n=arr.size(),l=0,sm=0;
        int ans=0;
        while(r<n)
        {
            sm+=arr[r];
            if(r-l+1 < k ){++r; continue;}
          //  if(r-l+1>k) { sm-=arr[l++];}
            if(sm >= k *threshold) {ans++; }
            sm-=arr[l++];
            ++r;
        }
        return ans;
    }
};