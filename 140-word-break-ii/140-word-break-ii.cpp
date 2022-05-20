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
    void insert(string &s)
    {
        Node* tmp = root;
        for(auto &el : s)
        {
            if(tmp->links[el-'a'] == NULL)
                tmp->links[el - 'a'] = new Node();
            tmp = tmp->links[el - 'a'];
        }
        
        tmp->flag = 1;
    }
    bool isPrefix(string s)
    {
        Node* tmp = root;
        for(auto &el : s)
        {
            if(tmp->links[el - 'a'] == NULL) return false;
            tmp = tmp->links[el - 'a'];
        }
   //     cout<<s<<" "<<tmp->flag<<"";
        return tmp->flag == true;
    }
};
void check(string s,int i,vector<string> &ans,Trie* obj,string prefix,string s1)
{  
    if(i == s.size())
    {
        if(obj->isPrefix(prefix))
        {
           // s1.pop_back();
            ans.push_back(s1);
        }
        return ;
    }
    prefix+=s[i];
   //  cout<<prefix<<" "<<i<<"\n";
    if(obj->isPrefix(prefix))
    {
     check(s,i+1,ans,obj,"",s1+s[i]+" ");   
    }
    check(s,i+1,ans,obj,prefix,s1+s[i]); 
}
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* obj = new Trie();
        for(auto &s : wordDict)
        {
            obj->insert(s);
        }
        vector<string> ans;
        check(s,0,ans,obj,"","");
        return ans;
    }
};