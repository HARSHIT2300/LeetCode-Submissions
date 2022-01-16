class StockSpanner {
    vector<int> v;
    stack<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i=v.size();
        int ans;
        while(!st.empty() && v[st.top()] <= price) {st.pop();}
        if(st.empty()) ans = i+1;
        else ans = i-st.top();
        st.push(i);
        v.push_back(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */