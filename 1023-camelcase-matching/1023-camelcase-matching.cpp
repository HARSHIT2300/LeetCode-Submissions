class Node
{   public:
    bool flag;
    Node* links[126];
    Node()
    {
        flag = false;
        for(int i=0;i<126;i++)
            links[i] = NULL;
    }
};
Node* root;
class Trie{
    public : 
    Trie()
    {
        root = new Node();
    }
    void insert(string& s)
    {
        Node* tmp = root;
        for(auto &el : s)
        {   int ch_val = el;
            if(tmp->links[ch_val] != NULL) tmp = tmp->links[ch_val];
            else
            {
                Node* tmp1 = new Node();
                tmp->links[ch_val] = tmp1;
                tmp = tmp1;
            }
        }
        tmp->flag = true;
    }
    bool search(string &s)
    {   Node* tmp = root;
        for(auto &el : s)
        {   int ch_val = el;
            if(el>=97&&el<=122){
                if(tmp->links[ch_val]!= NULL) tmp = tmp->links[ch_val];
                continue;
            }
            if(tmp->links[ch_val] == NULL) return false; 
         tmp = tmp->links[ch_val];
        }
     return tmp->flag == true;
    }
};
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie* obj = new Trie();
        obj->insert(pattern);
        vector<bool> ans;
        for(auto &s : queries)
        {   bool a1 = obj->search(s);
            ans.push_back(a1);
        }
        return ans;
    }
};