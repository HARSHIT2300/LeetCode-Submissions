// another soln just to check

const int inf = 1e6;
int cache[6005][2];
int a,b,x;
int check_forbidden[6005];
int dp(int cur,int f)
{
    // f - > previously how many consecutive backward operation perform.
    //cur -> cur position of bug.   
   // stop condition of Memoization
    if(cur < 0 or cur > 6000 or check_forbidden[cur] or f >= 2) 
        return inf;
    if(cur == x)
        return 0;
    int &ans = cache[cur][f];
    if(ans != -1)
        return ans;
    // forward operation
    ans = dp(cur+a,0) + 1;
    // backward operation 
    ans = min(ans , dp(cur-b , f+1)+1);
    return ans;
	
}
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a1, int b1, int x1) {
        a = a1,b = b1,x = x1;
        // initialize  check_forbidden array by zero      
        memset(check_forbidden,0,sizeof(check_forbidden));
        // make the position in check_forbidden array 1 where bug cannot jump.     
        for(auto it : forbidden)
            check_forbidden[it] = 1;
        // initialize  cache array by -1 
        memset(cache,-1,sizeof(cache));
        int ans = dp(0,0);
        // means no possible sequence found         
        if(ans >= inf)
            ans = -1;
        return ans;
    }
};