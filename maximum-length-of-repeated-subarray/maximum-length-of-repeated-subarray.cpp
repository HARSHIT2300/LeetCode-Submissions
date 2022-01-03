class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int ans =0;
        for(int i=0;i<n1;i++)
        {   if(ans>n1-i)break;
            for(int j=0;j<n2;j++)
            {   int res=0; int i1=i,j1=j;
                if(ans>n2-j) break;
                while(i1<n1&&j1<n2&&nums1[i1] == nums2[j1])
                {
                    ++i1; ++j1;     
                    ++res;
                }
             ans=max(ans,res);
            }
        }
        return ans;
    }
};