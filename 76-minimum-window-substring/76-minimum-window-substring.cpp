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
            //implementing the above if condition before bcoz only if we currently our window doesnt have the reqd characters to match string t when (rqd>0) then only we would increase the value of r
            if(rqd==0)
            {  
                if(r-l+1<sz)
                {
                    sz=r-l+1; st=l;
             
                }
                cnt[s[l]]++;
                if(cnt[s[l]]>0) rqd++;
                l++; 
            }
  
        }
        string ans="";
      
        if(st!=-1)ans=s.substr(st,sz);
        return ans;
    }
};