#include <cstring>
class Node{
     public :
    Node* links[26];
    bool flag;
   
    Node()
    {
        flag = false;
        for(int i = 0;i<26;i++)
            links[i] = NULL;
    }
};
Node* root;
class Trie{
    public :
    Trie(){
        root = new Node();
    }
    void insert(string &s){
        Node* tmp = root;
        for(int i = 0;i<s.length();i++)
        {   int ch_val = s[i]-97;
            if(tmp->links[ch_val] != NULL)
            {
                tmp = tmp->links[ch_val];
            }
            else
            {
                Node* tmp1 = new Node();
                tmp->links[ch_val] = tmp1;
                tmp = tmp1;
            }
        }
        tmp->flag = true;
    }
    string is_prefix(string &s)
    {
         Node* tmp = root;
        string ans="";
        for(int i = 0;i<s.length();i++)
        {   int ch_val = s[i]-97;
           
            if(tmp->links[ch_val] == NULL)
            return "\0";
         ans+=s[i];
            tmp =   tmp->links[ch_val] ;
             if(tmp->flag)break; 
        }
        return ans;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* obj = new Trie();
        for(auto &el : dictionary)
        {
            obj->insert(el);
        }
        vector<string> v;
        string s ="",ans="";
        for(auto &el : sentence)
        {
            if(el == ' '){
                v.push_back(s); s="";}
            else s+=el;
        }
        v.push_back(s);
        for(int i=0;i<v.size();i++)
        {   string el = v[i];
            if(obj->is_prefix(el)!="\0") ans+=obj->is_prefix(el);
            else ans+=el;
            if(i != v.size()-1)
            ans+=" ";
        }
       // ans = ans.substr(0,ans.length()-1);
        return ans;
    }
};