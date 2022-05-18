class Node{
    public :
    map<string,Node*> links;
    bool flag;
    Node()
    {
        flag = 0;
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
    {   string s1 = "";
     Node* tmp = root;
     s+="/";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '/')
            {
                if(i!=s.size()) s1+=s[i];
                if(tmp->links[s1] == NULL){
                    tmp->links[s1] = new Node();
            //    cout<<tmp->links[s1]<<"\n";
                }
                tmp = tmp->links[s1];
                s1 = "";
               
            }
            else
                s1 += s[i];
            
        }
       tmp->flag =1;
    
    }
    void check(Node* tmp,string s,vector<string> &ans)
    {
        if(tmp == NULL) return ;
      //  cout<<s<<" ";
        if(tmp->flag)
        {
            s.pop_back();
            ans.push_back(s);
            return ;
        }
    //    cout<<tmp->links.size()<<" ";
        for(auto &mp : tmp->links)
        {
      //      cout<<s<<" ";
            check(mp.second,s+mp.first,ans);
        }
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* obj = new Trie();
        for(auto &s : folder)
        {
            obj->insert(s);
        }
        vector<string> ans;
      //  cout<<root->links.size()<<" ";
        obj->check(root,"",ans);
        return ans;
    }
};