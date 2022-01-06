class Solution {
public:
  
    int balancedString(string s) {
        string s1 = "";
        int n=s.size();
        int q=0,w=0,e=0,r=0;
        for(auto &el : s)
        {
            if(el == 'Q')q++;
            else if (el == 'R')r++;
            else if(el == 'W')w++;
            else e++;
        }
      //  cout<<q<<" "<<w<<" "<<e<<" "<<r<<" ";
        while(q-(n/4)>0) {s1+="Q"; q--;}
        while(w-(n/4)>0) {s1+="W"; w--;}
        while(e-(n/4)>0) {s1+="E"; e--;}
        while(r-(n/4)>0) {s1+="R"; r--;}
        if(s1.size()==0) return 0;
    //  cout<<s1<<" ";
        unordered_map<char,int> mp1;
        for(auto &el : s1) mp1[el]++;
        int i=0,j=0,ans=s.size();
        int ct = mp1.size();
        while(j<n)
        {
           if(mp1.find(s[j]) == mp1.end()){ j++; continue;}
            
            mp1[s[j]]--;
            
            if(!mp1[s[j]]) ct--;
         //    cout<<i<<" "<<j<<" "<<ct<<"\n";
            while(ct==0)
            {   // cout<<i<<" "<<j<<" "<<ct<<"\n";
                ans = min(ans,j-i+1);
                if(mp1.find(s[i]) != mp1.end()){
                mp1[s[i]]++;
                if(mp1[s[i]]>0) ct++;}
                i++;
            }
          
            ++j;
        }
        return ans;
    }
};