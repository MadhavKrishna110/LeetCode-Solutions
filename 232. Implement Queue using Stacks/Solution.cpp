class MyQueue {
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> y;
        while(!s.empty()){
            y.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!y.empty()){
            s.push(y.top());
            y.pop();
        }
    }
    
    int pop() {
        int num = s.top();
        s.pop();
        return num;

    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
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