class MyQueue {
public:
    stack<int> stk;
    int top = 0;    // Top element in the queue
    
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (stk.empty())    top = x;
        stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> stk2;
        while (stk.size() > 1) {
            stk2.push(stk.top());    stk.pop();
        }
        int r = stk.top();    stk.pop();
        
        if (!stk2.empty())    top = stk2.top();    // Reset the top value to second bottom element in the stack
        
        // Push elements back to stk
        while (!stk2.empty()) {
            stk.push(stk2.top());    stk2.pop();
        }
        
        return r;
    }
    
    /** Get the front element. */
    int peek() {
        return top;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
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