class Solution {
public:
    bool check(unordered_map<char,int> &mp,unordered_map<char,int> &mp1)
    {
        for(auto &el : mp1)
        {
            if(mp[el.first]<el.second) return false;
        }
        return true;
    }
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
        cout<<q<<" "<<w<<" "<<e<<" "<<r<<" ";
        while(q-(n/4)>0) {s1+="Q"; q--;}
        while(w-(n/4)>0) {s1+="W"; w--;}
        while(e-(n/4)>0) {s1+="E"; e--;}
        while(r-(n/4)>0) {s1+="R"; r--;}
        if(s1.size()==0) return 0;
      //  cout<<s1<<" ";
        unordered_map<char,int> mp,mp1;
        for(auto &el : s1) mp1[el]++;
        int i=0,j=0,ans=s.size();
        while(j<n)
        {
            mp[s[j]]++;
            while(check(mp,mp1))
            {
                ans = min(ans,j-i+1);
                mp[s[i]]--;
                i++;
            }
       //     cout<<i<<" "<<j<<" "<<ans<<"\n";
            ++j;
        }
        return ans;
    }
};