class MyStack {
    queue<int> que;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que.size();
        for (int i = 0; i < size - 1; i++) {
            int out = que.front();    que.pop();
            que.push(out);
        }
        int ret = que.front();    que.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int ret = pop();
        que.push(ret);
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
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