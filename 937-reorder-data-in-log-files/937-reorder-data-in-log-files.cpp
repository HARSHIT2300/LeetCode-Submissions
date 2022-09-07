class Solution {
public:
    bool is_digit(string s)
    {  
        int f_space = s.find(' ');
        int s_space = s.find(' ',f_space+1);
        string suf =  s.substr(f_space+1, s_space - f_space);
        for(int i=0;i<suf.size();i++)
        {   int ch = (char)suf[i];
            if(ch >= 48 && ch<= 57) return true;
            else return false;
        }
        return true;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digit_logs;
        map<pair<string,string>,string> mp;
         vector<string> ans;
        for(auto &el : logs)
        {
            if(is_digit(el))
                digit_logs.push_back(el);
            else
            {
        string s = el;
        int f_space = s.find(' ');
        //int s_space = s.indexOf(' ',f_space+1);
        string pfx = s.substr(0,f_space);
        string suf =  s.substr(f_space+1, s.size() - f_space -1);
        mp[{suf,pfx}] = s;        
                
            }
        }
        for(auto &el : mp)
        {
            ans.push_back(el.second);
        }
         for(auto &el : digit_logs)
         {
             ans.push_back(el);
         }
            return ans;
        
    }
};