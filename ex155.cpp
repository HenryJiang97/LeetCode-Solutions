// Hash Map

class MinStack {
public:
    stack<int> s;
    int MIN = INT_MAX, cnt = 0;
    unordered_map<int, int> map;    // Save the minimum number while the stack has i items
    
    /** initialize your data structure here. */
    MinStack() {
        map[0] = INT_MAX;
    }
    
    void push(int x) {
        s.push(x);
        MIN = min(MIN, x);
        map[++cnt] = MIN;
    }
    
    void pop() {
        s.pop();
        map.erase(cnt--);
        MIN = map[cnt];
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return map[cnt];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */