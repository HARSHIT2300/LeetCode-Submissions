  map<string,int> mp;
class MagicDictionary {
public:
    
    MagicDictionary() {
      mp.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &el : dictionary)
        {
            mp[el]++;
        }
    }
    
    bool search(string searchWord) {
        for(auto &w1 : mp)
        {
            int dif = 0,f=1;
            if(searchWord.length() != w1.first.length()) continue;
            for(int i=0;i<searchWord.length();i++)
            {
                if(searchWord[i] != w1.first[i]) dif++;
                if(dif > 1){
                    f=0; break;
                }
            }
            if(dif == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */