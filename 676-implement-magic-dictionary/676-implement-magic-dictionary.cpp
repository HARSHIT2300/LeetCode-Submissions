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
          // means currently the link till which we have reached is not the end of any word that exists in the trie data structure
            if(mv == 0) return true;
         // only if we have exhausted our 1 move is when we satisfy the conditions is the question
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
                            // analytically think that we could only replace e by a in hello by hallo when we are currently at e and we oviously would move to the next reference of e , while conidering e's replacement by some other character only whose nextlink is NULL. Also consider the fact that you must have your current move remaining i.e mv should be equal to one 
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
                  // analytically think that we could only replace e by a in hello by hallo when we are currently at e and we oviously would move to the next reference of e , while conidering e's replacement by some other character only whose nextlink is NULL
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