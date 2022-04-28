class Node
{
    public : 
    bool flag;
    Node *links[26];
    Node()
    {
        flag = false;
        for(int i=0;i<26;i++)
        {
            links[i] = NULL;
        }
    }
};
Node *root;
class Trie
{
    public:
    Trie()
    {
        root  = new Node();
    }
    void insert(string &s)
    {   Node* tmp = root;
        for(auto &el : s)
        {   int ch_val = el-97;
           
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
    bool search(string s)
    {   Node *tmp = root;
        for(auto &el : s)
        {   int ch_val= el-97;
            if(tmp->links[ch_val] == NULL) return false;
         tmp = tmp->links[ch_val];
        }
     cout<<tmp->flag<<" "<<s<<"\n";
     return tmp->flag == true;
    }
};
class Solution {
public:
    bool cmp_lxc(string &s1,string &s2)
    {
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i] > s2[i]) return false;
            else if(s1[i] < s2[i]) return true;
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        Trie* obj = new Trie();
        for(auto &s : words)
        {
            obj->insert(s);
        }
        string ans = "";
        for(auto &s : words)
        {   string s1 = "";
            for(auto &el : s)
            {   s1+=el;
                if(obj->search(s1))
                {
                    if(s1.length() > ans.length()) ans = s1;
                    else if(s1.length() == ans.length() && cmp_lxc(s1,ans)) ans = s1;
                }
             else break;
            }
        }
        return ans;
    }
};