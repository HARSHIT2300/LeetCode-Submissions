class FreqStack {
     unordered_map <int,int> cnt;
     unordered_map <int,stack<int>> cnt_st;
    int max_freq;
public:
  
    FreqStack() {
    max_freq = 0;
     
    }
    
    void push(int val) {
     cnt[val]++;
        max_freq = max(max_freq,cnt[val]);
        cnt_st[cnt[val]].push(val);
    }
    
    int pop() {
     int ans = cnt_st[max_freq].top();
    cnt_st[max_freq].pop();
        cnt[ans]--;
        if(cnt_st[max_freq].empty()) max_freq--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */