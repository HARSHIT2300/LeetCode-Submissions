class FrontMiddleBackQueue {
    deque<int> dq;
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        stack<int> tmp;
        int k = dq.size()/2;
        while(k)
        {   tmp.push(dq.front());
            dq.pop_front();
            k--;
        }
        dq.push_front(val);
        while(!tmp.empty())
        {
            dq.push_front(tmp.top());
            tmp.pop();
        }
    }
    
    void pushBack(int val) {
        
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.empty()) return -1;
        int a = dq.front();
        dq.pop_front();
        return a;
    }
    
    int popMiddle() {
        if(dq.empty()) return -1;
       int k = (dq.size()+1)/2; int a;
        stack<int> tmp;
        while(k--)
        {  
            a = dq.front();
            dq.pop_front();
            tmp.push(a);
        }
        a =  tmp.top(); tmp.pop();
        while(!tmp.empty())
        {
            dq.push_front(tmp.top());
            tmp.pop();
        }
        return a;
    }
    
    int popBack() {
         if(dq.empty()) return -1;
        int a = dq.back();
        dq.pop_back();
        return a;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */