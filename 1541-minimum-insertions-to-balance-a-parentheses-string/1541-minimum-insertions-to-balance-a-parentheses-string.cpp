class Solution {
public:
    int minInsertions(string s) {
       int f=0; int n=s.length();
        stack<int> st; int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '('){
                if(f){
                    if(st.empty()) ans+=2;
                    else {
                        st.pop(); ans+=1;
                    }
                    f=0;
                }
                st.push(i);
            }
            else
            {
                f++;
                if(f==2)
                {
                    if(st.empty()) ans++;
                    else st.pop();
                    f=0;
                }
            }
           
        }
          if(f){
                    if(st.empty()) ans+=2;
                    else {
                        st.pop(); ans+=1;
                    }
                }
        
            ans+=(st.size()*2);
        return ans;
    }
};