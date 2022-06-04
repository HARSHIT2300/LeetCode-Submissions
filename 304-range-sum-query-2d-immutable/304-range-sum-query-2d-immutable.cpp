class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& matrix) {
        v = matrix;
        for(int i=0;i<v.size();i++)
        {   
            for(int j = 1;j<v[0].size();j++)
            {
               v[i][j]+=v[i][j-1];
              
            }
      
        }
        for(int j=0;j<v[0].size();j++)
        {
            for(int i=1;i<v.size();i++)
            {
                v[i][j]+= v[i-1][j];
            }
        }
      
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = v[row2][col2];
     //   cout<<ans<<" ";
        if(col1!=0)
            ans-=v[row2][col1-1];
       // cout<<ans<<" ";
        if(row1!=0)
            ans-=v[row1-1][col2];
        if(row1&&col1)
            ans+=v[row1-1][col1-1];
     //   cout<<ans<<"\n";
        return ans;    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */