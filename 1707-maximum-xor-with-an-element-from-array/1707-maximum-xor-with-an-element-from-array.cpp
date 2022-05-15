class Node{
    public : 
    Node* links[2];
    int num;
    Node(){
        for(int i=0;i<2;i++)
            links[i] = NULL;
        num = 0;
    }
};
Node* root;
class Trie{
    public : 
    Trie(){
        root = new Node();
    }
    void insert(int n)
    {   Node *tmp = root;
        int n1 = 1<<30;
        while(n1)
        {
          int b_val;
            if(n&n1) b_val = 1;
            else b_val = 0;
            if(tmp->links[b_val] != NULL) 
                tmp = tmp->links[b_val];
            else
            {
                Node *tmp1 = new Node();
                tmp->links[b_val] = tmp1;
                tmp = tmp1;
            }
            n1>>=1;
        }
     tmp->num = n;
    }
    int  max_xor(int n )
    {
        int n1 = 1<<30;
        int ans=0;
        int f=0;
        Node* tmp = root;
        while(n1)
        {
            int b_val_n;
            int b_val_m;
            if(n&n1)
                b_val_n = 1;
            else 
                b_val_n = 0;
            
          
                if(tmp->links[b_val_n ^ 1] == NULL)
                    tmp = tmp->links[b_val_n];
                else
                {
                    tmp = tmp->links[b_val_n ^ 1];
                    ans+=n1; f = n1;
                }
            
          
            n1>>=1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* obj = new Trie();
        vector<pair<int,pair<int,int>>> queries1;
       // cout<<queries.size()<<" ";
        for(int j=0;j<queries.size();j++)
        {
            queries1.push_back({queries[j][1],{queries[j][0],j}});
        }
     
        sort(nums.begin(),nums.end());
        sort(queries1.begin(),queries1.end());
        vector<int> res(queries.size(),-1);
        int i=0;
        for(auto &p1 : queries1)
        {
           while(i<nums.size() && nums[i]<= p1.first)
           {
               obj->insert(nums[i]);
               i++;
           }
            if(i)
                res[p1.second.second] = obj->max_xor(p1.second.first);
            else 
                res[p1.second.second] = -1;
        }
     
        return res;
    }
};