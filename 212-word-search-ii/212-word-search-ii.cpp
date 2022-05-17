class Node{
  public : 
    Node* links[26];
    bool flag;
    Node()
    {
        for(int i=0;i<26;i++) links[i] = NULL;
        flag = false;
    }
};
Node* root;
class Trie{
    public :
    Trie()
    {
        root = new Node();
    }
    void insert(string &s)
    {
        Node* tmp = root;
        for(auto &el : s)
        {
            int ch = el - 'a';
            if(tmp->links[ch] == NULL)
                tmp->links[ch] = new Node();
            tmp = tmp->links[ch];
        }
        tmp->flag = 1;
    }
};
void check(int x,int y,Node *tmp,int m,int n,vector<vector<char>>& board,vector<string>& res,string s)
{
    if(x<0||x>=m||y<0||y>=n||board[x][y] == '.' || tmp->links[board[x][y]-'a'] == NULL)
        return ;
    char ch = board[x][y];
    tmp = tmp->links[board[x][y] - 'a'];  
    s+=ch;
   
    if(tmp->flag == 1)
    {
        res.push_back(s);
        tmp->flag = 0;
    }
    board[x][y] = '.';
    check(x-1,y,tmp,m,n,board,res,s);
    check(x,y+1,tmp,m,n,board,res,s);
    check(x+1,y,tmp,m,n,board,res,s);
    check(x,y-1,tmp,m,n,board,res,s);
    board[x][y] = ch;
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* obj = new Trie();
        for(auto &el : words)
            obj->insert(el);
        int m = board.size(),n = board[0].size();
        vector<string> res;
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                check(i,j,root,m,n,board,res,"");
            }
        }
        return res;
    }
};