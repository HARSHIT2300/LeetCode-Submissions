class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
         vector<vector<int>> matrix1;
       vector<vector<int>> up(m,vector<int>(n,0));
        vector<vector<int>> down(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(matrix[i][j]-'0');
            }
            matrix1.push_back(v);
        }
       for(int i=0;i<m;i++)
       {
           for(int j=1;j<n;j++)
           {
               if(matrix1[i][j] == 1)
               {
                   matrix1[i][j]+=matrix1[i][j-1];
                   ans = max(ans,matrix1[i][j]);
               }
           }
        }
        // for(auto &v : matrix1)
        // {
        //     for(auto &el : v)
        //         cout<<el<<" ";
        //     cout<<"\n";
        // }
        for(int i=0;i<n;i++)
       {    stack<int> st;
           for(int j=0;j<m;j++)
           {
              
                while(!st.empty() && matrix1[st.top()][i] >= matrix1[j][i])
                {  
                    st.pop();
                }
                 if(st.empty())
                     {
                      up[j][i] = j+1;
                    
                 }
                 else
                     up[j][i] = j - st.top();
                  st.push(j);       
               
           }
        stack<int> st1;
          for(int j=m-1;j>=0;j--)
           {
              
                 
                while(!st1.empty() && matrix1[st1.top()][i] >= matrix1[j][i])
                {
                    st1.pop();
                }
                 if(st1.empty())
                     {
                     
                      down[j][i] = m-j;
                 }
                 else
                     down[j][i] = st1.top() - j;
                  st1.push(j);
                 ans = max(ans,(up[j][i]+down[j][i]-1)*matrix1[j][i]);
               }
              
               
           }  
      
        return ans;
    }
};