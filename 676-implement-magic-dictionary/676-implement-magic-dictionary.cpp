class Node{
   
    public :
    Node* links[26];
    bool flag;
    Node()
    {
        for(int i=0;i<26;i++) links[i] = NULL;
        flag = false;
    }
 };
Node* root;
 bool search_ag(string &Word,int i,int mv,Node* tmp)
    {   
        if(i == Word.size())
        {   if(tmp->flag == false) return false;
          
            if(mv == 0) return true;
            else return false;
        }
         int f=0;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            if(tmp->links[Word[i]-97] == NULL) f++;
        }
        bool ans = false;
        for(char ch = 'a';ch <= 'z';ch++)
        {   int ch_val = ch-97;
            if(tmp->links[ch_val] == NULL) continue;
         
            if(ch == Word[i]){
                ans= search_ag(Word,i+1,mv,tmp->links[ch_val]);
                if(ans) return ans;
                if(f && mv)
                  ans = search_ag(Word,i+1,0,tmp->links[ch-97]);
                if(ans) return ans;
            }
            else
            {
                if(mv)
                    ans = search_ag(Word,i+1,0,tmp->links[ch_val]);
            }
               if(ans) return ans; 
        }
        return ans;
    }
class MagicDictionary {
public:
    
    MagicDictionary() {
     root = new Node();
   MagicDictionary*   obj;
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &s : dictionary)
        {
            Node *tmp = root;
            for(auto &el : s)
            {   int ch_val = el-97;
                if(tmp->links[ch_val] != NULL)
                    tmp = tmp->links[ch_val];
                else
                {
                    Node* tmp1 = new Node();
                    tmp->links[ch_val] = tmp1;
                    tmp = tmp1;
                }
            }
            tmp->flag = true;
        }
        
    }
   
    bool search(string searchWord) {
       
        bool ans = false;
        int f=0;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            if(root->links[searchWord[0]-97] == NULL) f++;
        }
      for(char ch = 'a'; ch<='z'; ch++)
      {
          if(root->links[ch-97] == NULL) continue;
          
          if(ch == searchWord[0]){
              ans= search_ag(searchWord,1,1,root->links[ch-97]);
              if(ans) return ans;
              if(f)
                  ans = search_ag(searchWord,1,0,root->links[ch-97]);
              if(ans) return ans;
          }
             
          else
           ans =  search_ag(searchWord,1,0,root->links[ch-97]);
          if(ans) return ans;
      }
        return ans;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */