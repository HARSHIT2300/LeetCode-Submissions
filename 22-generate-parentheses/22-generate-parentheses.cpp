class Solution {
public:
    void gen_rec(string s,int i,int j,int n,vector<string>& res)
    {
        if(s.length() == n*2){
            res.push_back(s);
            return ;}
        if(j==0)
            gen_rec(s+"(",i+1,j+1,n,res);
        else if(i == n)
            gen_rec(s+")",i,j-1,n,res);
        else
        {
             gen_rec(s+"(",i+1,j+1,n,res);
             gen_rec(s+")",i,j-1,n,res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen_rec("",0,0,n,res);
        return res;
    }
};