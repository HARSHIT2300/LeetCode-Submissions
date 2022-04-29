class Node{
    public : 
    Node* links[2];
    int num;
    Node()
    {
        for(int i=0;i<2;i++) links[i] = NULL;
        num = 0;
    }
};
Node *root;
class Trie{
    public : 
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *tmp = root;
        int n1 = 1<<30;
        string s1 = "";
        while(n1)
        {  
           
            if(n1&n){
                if(tmp->links[1]!=NULL) 
                {
                    tmp = tmp->links[1]; 
                }
                else
                {
                 Node *tmp1 = new Node();
                tmp->links[1] = tmp1;
                tmp = tmp1; s1+="1";}
            }
            else{
                 if(tmp->links[0]!=NULL) 
                {
                    tmp = tmp->links[0]; 
                }
                else
                {
                 Node *tmp1 = new Node();
                tmp->links[0] = tmp1;
                tmp = tmp1; s1+="0";
                }
            }
           
            n1>>=1;
        }
    
        tmp->num = n;
    }
    int max_xor(int n)
    {   Node* tmp = root;
     int ans=0,n1=1<<30;
        while(n1)
        {   
            int b_val ;
            b_val = n & n1;
            if(b_val) b_val = 1;
            if(tmp->links[b_val^1]!=NULL){
                tmp = tmp->links[b_val^1];
                ans+=n1;}
            else
                tmp = tmp->links[b_val];
            n1>>=1;
         
        }
 
     return tmp->num ^ n;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* obj = new Trie();
        
        for(auto &el : nums)
        {
                obj->insert(el);    
        }
        int ans = 0;
        for(auto &el : nums)
        {
            ans  = max(ans,obj -> max_xor(el));
       
        }
        return ans;
    }
};