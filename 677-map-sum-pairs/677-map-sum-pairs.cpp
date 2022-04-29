unordered_map<string,int> mp;
class Node{
  public:
    int flag;
    Node* links[26];
    Node(){
        flag = 0;
        for(int i=0;i<26;i++) links[i] = NULL;
    }
    
};
Node* root;
class MapSum {
public:
    MapSum() {
        root = new Node();
        mp.clear();
    }
    
    void insert(string key, int val) {
        Node*tmp = root;
        int v1 = val;
        if(mp[key]) {
            val-=mp[key];
           
        }
       // cout<<val<<" ";
         mp[key] = v1;
        for(auto &el : key)
        {   int ch_val = el - 97;
            if(tmp->links[ch_val] == NULL)
            {
                Node* tmp1 = new Node();
                tmp->links[ch_val] = tmp1;
                tmp = tmp1;
            }
            else
            {
                tmp = tmp->links[ch_val];
            }
         tmp->flag += val;
        }
        
    }
    
    int sum(string prefix) {
        int ans = 0;
        Node* tmp = root;
        for(auto &el : prefix)
        {   int ch_val = el - 97;
            if(tmp->links[ch_val] == NULL)
            {
                return 0;
            }
         tmp = tmp->links[ch_val];
        }
        return tmp->flag;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */