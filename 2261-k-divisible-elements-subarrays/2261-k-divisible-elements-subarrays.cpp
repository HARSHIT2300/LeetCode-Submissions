class Node{
    public : 
    map<int,Node*> links;   
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int ans = 0;
       Node* root = new Node();
        for(int l=0;l<nums.size();l++)
        {   int ct=0;
            Node *tmp  = root;
            
            for(int r=l;r<nums.size();r++)
            {
                if(nums[r] % p == 0)
                    ct++;
                if(ct > k) break;
                if(tmp->links[nums[r]] == NULL)
                {
                    tmp->links[nums[r]] = new Node();
                    ans++;
                }
                tmp = tmp->links[nums[r]];
            }
        }
        return ans;
    }
};