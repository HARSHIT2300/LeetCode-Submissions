class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l=0,r=0;
        vector<int> cnt(26,0);
         vector<int> cnt1(26,0);
        for(auto &el : p) {cnt[el-'a']++; cnt1[el-'a']++;}
        int n = s.size(),n1=p.size();
        vector<int> ans;
        while(r<n)
        {
            cnt[s[r]-'a']--;
            if(r-l+1<n1) { ++r; continue;}
            int f=1;
            for(int i=0;i<26;i++)
            {
                if(cnt[i]!=0&&cnt1[i]) {f=0; break;}
            }
            if(f){ans.push_back(l);  cnt[s[l]-'a']++; ++l;}
            ++r;
            if(r-l+1 > n1) {cnt[s[l]-'a']++;++l;}
        }
        return ans;
    }
};