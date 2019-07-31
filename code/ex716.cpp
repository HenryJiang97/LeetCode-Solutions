class MaxStack {
public:
    stack<int> stk;
    stack<int> maxStack;    // Store the max value under each layer in the stack
    
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        if (maxStack.empty() || x > maxStack.top())    maxStack.push(x);
        else    maxStack.push(maxStack.top());
        
        stk.push(x);
    }
    
    int pop() {
        maxStack.pop();
        int top = stk.top();    stk.pop();
        return top;
    }
    
    int top() {
        return stk.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {
        int MAX = maxStack.top();
        
        stack<int> temp;    // Store elements higher than max element in the stack
        while (stk.top() != MAX)    temp.push(pop());
        pop();
        
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
        
        return MAX;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */