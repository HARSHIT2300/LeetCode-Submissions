class Solution {
public:
    // Just a variation of N-Queens 
     bool isValid(int x,int y, int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }
    void calc(int x,int y,int n,int qc,vector<string> queens,int &ans)
    {
        if(qc == n)
        {
            ans+=1;
        }
        if(!isValid(x,y,n)) return ;
        bool flag = true;
        for(int row = n-1;row>=0;row--)
        {
            if(queens[row][y] == 'Q') { flag = false; break;}
        }
        if(flag){
             for(int row = x,col = y; isValid(row,col,n) == true ; row++,col++)
        {
            if(queens[row][col] == 'Q') { flag = false; break;}
        }
        }
       
         if(flag){
         for(int row = x,col = y; isValid(row,col,n) == true ; row++,col--)
        {
            if(queens[row][col] == 'Q') { flag = false; break;}
        }
         }
         if(flag){
         for(int row = x,col = y; isValid(row,col,n) == true ; row--,col++)
        {
            if(queens[row][col] == 'Q') { flag = false; break;}
        }
         }
          if(flag){
         for(int row = x,col = y; isValid(row,col,n) == true ; row--,col--)
        {
            if(queens[row][col] == 'Q') { flag = false; break;}
        }
         }
        
        if(flag){
            queens[x][y] = 'Q';
            calc(x+1,0,n,qc+1,queens,ans);
            queens[x][y] = '.';
        }
      //  else calc(row,col+1,qc,queens,ans);
        
        calc(x,y+1,n,qc,queens,ans);
    }
    int totalNQueens(int n) {
        int ans=0;
        string s="";
        for(int i=0;i<n;i++)
            s+=".";
        vector<string> queens(n,s);
        calc(0,0,n,0,queens,ans);
        return ans;
    }
};