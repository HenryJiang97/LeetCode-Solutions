// Maintain a maximum stack (containing the maximum value and count before curtain index), monotone descending stack

class StockSpanner {
    stack<pair<int, int>> stk;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!stk.empty() && stk.top().first <= price) {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({price, cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */