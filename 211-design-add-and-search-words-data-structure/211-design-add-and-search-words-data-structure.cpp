class Node{
    public : 
        Node* links[26];
        bool flag;
        Node()
        {
            for(int i=0;i<26;i++)
            {
                links[i] = NULL;
                flag = false;
            }
        }
};
Node* root;
bool search1(string& word,int i,Node* tmp)
{
    if(i == word.size())
    {
        return tmp->flag;
    }
    if(word[i] != '.' && tmp->links[word[i]-97] != NULL)
    {
        if(search1(word,i+1,tmp->links[word[i]-97])) return true;
    }
    if(word[i] == '.')
    {
        for(char ch = 'a';ch<='z';ch++)
        {
            if(tmp->links[ch-97] != NULL)
            if(search1(word,i+1,tmp->links[ch-97])) return true;
        }
    }
    return false;
}
class WordDictionary {
public:
    WordDictionary() {
        root  = new Node();
    }
    
    void addWord(string word) {
        Node* tmp = root;
        for(int i=0;i<word.size();i++)
        {
            if(tmp->links[word[i]-97] != NULL)
                tmp = tmp->links[word[i]-97];
            else
            {
                tmp->links[word[i]-97] = new Node();
                tmp = tmp->links[word[i]-97];
            }
        }
        tmp->flag = true;
    }
    
    bool search(string word) {
       return  search1(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */