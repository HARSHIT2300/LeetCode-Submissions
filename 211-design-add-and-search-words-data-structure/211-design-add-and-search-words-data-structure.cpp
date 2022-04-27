class Node{
    public : 
    Node* link[27];
    bool flag;
    Node()
    {
        flag = false;
        for(int i=0;i<=26;i++)
        {
            link[i] = NULL;
        }
    }
};
Node *root;
class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* tmp = root;
        
        for(auto &el : word)
        {
          
            int pos = el-97;
             if(el == '.') pos = 26;
            if(tmp->link[pos] == NULL)
            {
                Node *tmp1 = new Node();
                tmp->link[pos] = tmp1;
                tmp = tmp1;
            }
            else
                tmp = tmp->link[pos];
                
        }
        tmp->flag = true;
    }
    
    bool search(string word) {
        int f = 0;
        Node *tmp = root;
        for(int i = 0;i<word.length();i++)
        {
            if(word[i] == '.')
            {   bool f = false;
                for(char ch = 'a';ch<='z';ch++)
                {
                    string s1 = word.substr(i+1,word.length()-1-i);
                   
                    if( search1(s1,tmp->link[ch-97]))return true;
                }
                if(!f) return false;
                
            }
            else
            {
                 int pos = word[i] - 97;
                 if(tmp->link[pos] == NULL) return false;
                tmp = tmp->link[pos];
            }
        }
        return tmp->flag == true;
    }
    bool search1(string word,Node *tmp)
    {
        if(tmp == NULL) return false;
        for(int i = 0;i<word.length();i++)
        {
            if(word[i] == '.')
            {  bool f = false;
                for(char ch = 'a';ch<='z';ch++)
                {
                    string s1 = word.substr(i+1,word.length()-1-i);
                   
                    if( search1(s1,tmp->link[ch-97]))return true;
                }
             if(!f) return false;
            }
            else
            {
                 int pos = word[i] - 97;
                 if(tmp->link[pos] == NULL) return false;
                tmp = tmp->link[pos];
            }
        }
        return tmp->flag == true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */