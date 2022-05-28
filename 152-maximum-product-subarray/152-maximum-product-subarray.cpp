class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p1=1,p2=1,ct=0;
        int ans = nums[0];
        for(auto &el : nums)
        {
            if(el == 0)
            {
                ans = max(ans,0);
                p1=1;p2=1; ct=0; continue;
            }
            if(ct%2){
                p2*=el; ans=max(ans,p2);}
            else{
                p1*=el; ans=max(ans,p1);}
            
            if(el<0)
            {
                if(ct%2)
                {
                    p1*=p2; p2=1;
                    ans = max(p1,ans);
                }
                // else
                // {
                //     p2=1;
                // }
                ct++;
            }
      //      cout<<ans<<" "<<p1<<" "<<p2<<"\n";
        }
        p1=1;p2=1;ct=0;
        for(int i = nums.size()-1;i>=0;i--)
        {   int el = nums[i];
            if(el == 0)
            {
                ans = max(ans,0);
                p1=1;p2=1; ct=0; continue;
            }
            if(ct%2){
                p2*=el; ans=max(ans,p2);}
            else{
                p1*=el; ans=max(ans,p1);}
            
            if(el<0)
            {
                if(ct%2)
                {
                    p1*=p2; p2=1;
                    ans = max(p1,ans);
                }
             
                ct++;
            }
          //  cout<<ans<<" "<<p1<<" "<<p2<<"\n";
        }
        return ans;
    }
};