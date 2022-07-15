class MyQueue {
public:
    stack<int> s, t;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int ans=-1;
        if(t.empty()){
            while(!s.empty()){
                t.push(s.top());
                s.pop();
            }
        }
        ans = t.top();
        t.pop();
        return ans;
    }
    
    int peek() {
        int ans=-1;
        if(t.empty()){
            while(!s.empty()){
                t.push(s.top());
                s.pop();
            }
        }
        ans = t.top();
        return ans;
    }
    
    bool empty() {
        return s.empty() && t.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */