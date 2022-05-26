class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost[cost.size() + 1];
       // for(int i=0;i<=cost.size();i++) min_cost[i] = INT_MAX;
        min_cost[0] = 0; min_cost[1] = 0;
        for(int i=2;i<=cost.size();i++)
        {
            min_cost[i] = min(cost[i-1]+min_cost[i-1],cost[i-2]+min_cost[i-2]);
        }
        return min_cost[cost.size()];
    }
};