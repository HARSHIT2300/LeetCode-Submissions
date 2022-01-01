class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int sm =1;
        int pw = 0;
        vector<int> v(10,0);
            int n1=n;
        while(n1)
        {
            v[n1%10]++;
            n1/=10;
        }
        while(pw<=30)
        {
            vector<int> v1(10,0);
            n1=sm;
             while(n1)
        {
            v1[n1%10]++;
            n1/=10;
        }   int f=1;
            for(int i=0;i<10;i++) {
                if(v[i]!=v1[i]) {f=0; break;}
            }
            if(f) return true;
            sm<<=1;
            pw++;
        }
        return false;
    }
};