class Node{
    public :
    Node* link[26];
    bool flag;
    
    Node()
    {
        flag  = false;
        for(int i=0;i<26;i++)
            link[i]=NULL;
    }
};
Node* rt;
class Trie {
public:
    Trie() {
      rt = new Node();  
    }
    
    void insert(string word) {
        Node *tmp=rt;
        for(int i=0;i<word.length();i++)
        {   int pos = word[i]-97;
            if(tmp->link[pos] != NULL)
            {
                tmp =tmp -> link[pos];
            }
         else
         {
             Node* tmp1 = new Node();
             tmp->link[pos] = tmp1;
             tmp = tmp1;
         }
        }
        tmp->flag = true;
    }
    
    bool search(string word) {
        Node* tmp = rt;
        for(int i=0;i<word.length();i++)
        {
            int pos = word[i]-97;
            if(tmp->link[pos] == NULL) return false;
            tmp = tmp->link[pos];
        }
        return(tmp->flag == true);
        
    }
    
    bool startsWith(string prefix) {
         Node* tmp = rt;
        for(int i=0;i<prefix.length();i++)
        {
            int pos = prefix[i]-97;
            if(tmp->link[pos] == NULL) return false;
            tmp = tmp->link[pos];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */