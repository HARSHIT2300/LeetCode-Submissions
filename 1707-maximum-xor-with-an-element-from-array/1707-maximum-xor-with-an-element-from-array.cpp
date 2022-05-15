class Node{
    public : 
    Node* links[2];
    int num;
    // Node(){
    //     for(int i=0;i<2;i++)
    //         links[i] = NULL;
    //     num = 0;
    // }
};
Node* root;
class Trie{
    public : 
    Trie(){
        root = new Node();
    }
    void insert(int n)
    {   Node *tmp = root;
     
       for(int bit = 31;bit>=0;bit--)
       {    int b_val = (n>>bit) & 1;
          
            if(tmp->links[b_val] != NULL) 
                tmp = tmp->links[b_val];
            else
            {
                Node *tmp1 = new Node();
                tmp->links[b_val] = tmp1;
                tmp = tmp1;
            }
           
        }
     tmp->num = n;
    }
    int  max_xor(int n)
    {
      
        int ans=0;
       
        Node* tmp = root;
       for(int bit = 31;bit>=0;bit--)
       {    int b_val = (n>>bit) & 1;
          
          
                if(tmp->links[1 - b_val] == NULL)
                    tmp = tmp->links[ b_val];
                else
                {
                   tmp = tmp->links[1 - b_val];
                  
                }
       }  
        return tmp->num ^ n;
       // return 0;
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