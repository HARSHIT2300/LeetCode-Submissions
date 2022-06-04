class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==1) return 0;
        vector<int> lmax(n+1,0);
        vector<int> rmax(n+1,0);
        int lmx = height[0],rmx = height[n-1];
        for(int i=1;i<n;i++)
        {
            lmax[i] = lmx;
            lmx = max(lmx,height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rmax[i] = rmx;
            rmx = max(rmx,height[i]);
        }
        int ans =0;
        for(int i = 1;i<n-1;i++)
        {
            if(height[i] < min(rmax[i],lmax[i]))
                ans += min(rmax[i],lmax[i]) - height[i];
        }
        return ans;
    }
};