class Solution {
public:
//    alternate approach
    string minWindow(string s, string t) {
      vector<int> cnt(128,0);
        int rqd = t.size();
        for(auto &el : t) cnt[el]++;
        int l=0,r=-1;
        int st =-1,sz = 1000000;
        while(l<=s.size()-t.size())
        {
            if(rqd>0)
            {
           
            r++;
                 if(r==s.size())
                 {
                   break;
                 }
                cnt[s[r]]--;
            if(cnt[s[r]]>=0) rqd--;
            }
            if(rqd==0)
         
            {  //  cout<<l<<" "<<r<<"\n";
                if(r-l+1<sz)
                {
                    sz=r-l+1; st=l;
                 //   cout<<st<<" "<<sz<<" ";
                }
           //  cout<<cnt[s[l]]<<" ";
         // cout<<cnt[99]<<" ";
                cnt[s[l]]++;
                if(cnt[s[l]]>0) rqd++;
           cout<<rqd<<""<<s[l]<<"\n";
                l++; 
               
            }
       //   cout<<l<<" "<<r<<"\n";
        }
        string ans="";
       // cout<<st<<" ";
        if(st!=-1)ans=s.substr(st,sz);
        return ans;
    }
};