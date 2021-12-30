class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans = 0;
        int n=piles.size();
        int ct = n/3; int i = 2;
        while(ct--)
        {
          ans+=  piles[n-i];
            i+=2; //cout<<ans<<" ";
        }
        return ans;
    }
};