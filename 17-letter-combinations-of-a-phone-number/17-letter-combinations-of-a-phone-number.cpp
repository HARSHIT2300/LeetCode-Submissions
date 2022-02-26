class Solution {
public:
    void calc(string &digits,string res,vector<string> &v,vector<string> &ans)
    {
        if(digits.size() == res.size()){
            if(res.size())
            ans.push_back(res);
            return ;}
        int i=res.size();
        int ch = digits[i]-50; 
        calc(digits,res+v[ch][0],v,ans);
        calc(digits,res+v[ch][1],v,ans);
        calc(digits,res+v[ch][2],v,ans);
        if(ch == 5 || ch == 7)
            calc(digits,res+v[ch][3],v,ans);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v(8);
        v[0]="abc";v[1]="def";v[2]="ghi";v[3]="jkl";v[4]="mno";v[5]="pqrs";v[6]="tuv";v[7]="wxyz";
        
        vector<string> ans;
        calc(digits,"",v,ans);
        return ans;
    }
};