class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int m=matrix.size(),n=matrix[0].size(); 
        vector<vector<int>> matrix1,matrix2; matrix1=matrix; matrix2=matrix;
        vector<vector<int>> ans(m,vector<int>(n));
        ans[0][0]=matrix[0][0];
        pq.push(matrix[0][0]);
        for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            matrix[j][i]^=matrix[j][i-1]; 
            if(j==0){pq.push(matrix[j][i]);  }
        }
        }
         for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            matrix[i][j]^=matrix[i-1][j]; 
           pq.push(matrix[i][j]);
        }
         }
       
        while(--k)
        {
            pq.pop();
        }
        return pq.top();
    }
};