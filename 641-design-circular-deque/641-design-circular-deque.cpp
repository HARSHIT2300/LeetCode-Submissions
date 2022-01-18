class MyCircularDeque {
    deque<int> dq;
    int sz;
public:
    MyCircularDeque(int k) {
        sz = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        dq.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        dq.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        dq.pop_front(); return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        dq.pop_back(); return true;
    }
    
    int getFront() {
         if(isEmpty()) return -1;
        return dq.front();
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == sz;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */