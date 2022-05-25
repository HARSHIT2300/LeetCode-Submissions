class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     
        int min_coins[amount+1];
        memset(min_coins,-1,sizeof(min_coins));
        min_coins[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(auto &el : coins)
            {
                if(i-el < 0 || min_coins[i-el] == -1)continue;
                if(min_coins[i] == -1) min_coins[i] = min_coins[i-el]  + 1;
                else
                    min_coins[i] = min(min_coins[i-el] + 1,min_coins[i]);
            }
        }
        
        return min_coins[amount];
    }
};