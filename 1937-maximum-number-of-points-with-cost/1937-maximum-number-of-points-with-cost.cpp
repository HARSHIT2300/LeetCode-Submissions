class Solution {
public:
    long long maxPoints(vector<vector<int>>& points1) {
        // calc max prefix  max suffix for each row and add max out of these to the next row
        //0 - n-1 
        
        long long int ans = 0LL;
        int m = points1.size();
        int n = points1[0].size(); // m rows n cols
        vector<vector<long long int>> points;
        for(int row=0; row < m; row++)
        {   vector<long long int> v;
            for(int col = 0; col< n ;col++)
            {
                v.push_back(points1[row][col]);
            }
         points.push_back(v);
        }
        for(int row = 0; row < m-1 ; row++)
        {   
            vector<long long int> lmax(n,0); lmax[0] = (long long int)points[row][0];
            vector<long long int> rmax(n,0); rmax[n-1] = (long long int)points[row][n-1];
            
            for(int col = 1;col < n; col++)
            {
                lmax[col] = max((long long int)points[row][col],lmax[col-1]-1);
            }
            for(int col = n-2;col >=0; col--)
            {
                rmax[col] = max((long long int)points[row][col],rmax[col+1]-1);
            }
            for(int col= 0; col < n;col++)
            {
                points[row+1][col]+=max(lmax[col],rmax[col]);
            }
        //    cout<<points[row+1][0]<<" ";
        }
      //  cout<<m<<" "<<n<<"\n";
        for(int col = 0;col < n; col++)
        {  // cout<<1<<" ";
            ans = max(ans,(long long int)points[m-1][col]);
          //  cout<<ans<<"\n";
        }
        
    return (long long)ans;
    } 

};