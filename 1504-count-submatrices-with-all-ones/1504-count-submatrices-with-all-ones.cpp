class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();   // m rows and n columns
        int suffix[m][n];
        
        for(int i=0;i<m;i++)
        {   int ct=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]) ct++;
                else ct=0;
                suffix[i][j] = ct;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   int top_left_ct=INT_MAX;
                for(int k=i;k<m;k++)
                {
                    top_left_ct = min(top_left_ct,suffix[k][j]);
                    ans += top_left_ct;
                }
            }
        }
        return ans;
    }
};