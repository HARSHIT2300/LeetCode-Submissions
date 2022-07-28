class Solution {
public:
    bool fill_board(int x,int y,vector<vector<char>>& board)
    {   //cout<<x<<" "<<y<<"\n";
        if(y == 9) {y=0;x+=1;}
        if(x == 9) return true;
        if(board[x][y] != '.') return  fill_board(x,y+1,board);
        bool flag = false;
      vector<int> v(10,0);
        for(int row = 0; row < 9 ; row++)
        {
            if(board[row][y] != '.')
            {
             v[board[row][y] - '0'] = 1;
            }
             if(board[x][row] != '.')
            {
                v[board[x][row] - '0'] = 1;
            }
        }
        int r = x/3, c = y/3;
        for(int i=r*3; i<(r+1)*3 ; i++)
        {
            for(int j = c*3; j<(c+1)*3; j++)
            {
                if(board[i][j] != '.')
                 v[board[i][j] - '0'] = 1;
            }
        }
        
        vector<char> s;
        for(int i=1;i<10;i++)
        {   char ch = (char)(48+i);
            if(!v[i])
                s.push_back(ch);
        }
        if(s.size() == 0) return false;
        for(auto &el : s)
        {
            board[x][y] = el;
            if(fill_board(x,y+1,board)) return true;
            board[x][y] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fill_board(0,0,board);
    }
};