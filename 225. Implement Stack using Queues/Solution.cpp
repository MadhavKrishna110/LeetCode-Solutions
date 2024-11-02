class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int siz=q.size();
        q.push(x);
        while(!q.empty() && siz>0){
            int temp = q.front();
            q.pop();
            q.push(temp);
            siz--;
        }
    }
    
    int pop() {
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()?false:true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */