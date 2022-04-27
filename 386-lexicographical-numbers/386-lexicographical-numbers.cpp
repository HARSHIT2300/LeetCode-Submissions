void calc(vector<int>&res, int a,int &n)
{
    for(int i=0;i<=9;i++)
    {
        int n1 = a*10+i;
        if(n1 == 0)continue;
         if(n1>n) return;
        if(n1) res.push_back(n1);
      
        calc(res,n1,n);
    }
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
      vector<int> res;
        calc(res,0,n);
        return res;
    }
};