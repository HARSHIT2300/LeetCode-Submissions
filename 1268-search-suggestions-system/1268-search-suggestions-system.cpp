class Node{
    public : 
    Node* links[26];
    bool flag;
    Node()
    {
        for(int i=0;i<26;i++)
            links[i] = NULL;
        flag = false;
    }
};
Node* root;
class Trie{
    public : 
    Trie()
    {
        root = new Node();
    }
    void accept(string &s)
    {
        Node* tmp = root;
        for(auto &el : s)
        {
            int ch = el-'a';
            if(tmp->links[ch] == NULL) tmp->links[ch] = new Node();
            tmp = tmp->links[ch];
        }
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* obj = new Trie();
        obj->accept(searchWord);
        set<string> res[searchWord.size()];
        for(auto &s : products)
        {  // string s = ""
            Node* tmp = root;
         for(int i=0;i<searchWord.size()&&i<s.size();i++)
         {
             if(tmp->links[s[i]-'a'] == NULL) break;       
             res[i].insert(s);
             tmp = tmp->links[s[i]-'a'];
         }
        }
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++)
        {
            vector<string> v;
            for(auto &s : res[i])
            {
                v.push_back(s);
                if(v.size() == 3) break;
            }
            ans.push_back(v);
        }
        return ans;
    }
};