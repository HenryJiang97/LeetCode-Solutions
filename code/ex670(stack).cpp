class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        stack<pair<char, int>> stk;    // Monotone stack
        for (int i = n.length() - 1; i >= 0; i--) {
            if (stk.empty() || stk.top().first < n[i]) {
                stk.push({n[i], i});
            }
        }
        
        for (int i = 0; i < n.length() - 1; i++) {
            char c = n[i];
            while (stk.top().second <= i)    stk.pop();
            if (stk.empty())    return stoi(n);
            if (stk.top().first <= c)    continue;
            // Swap
            n[i] = stk.top().first;
            n[stk.top().second] = c;
            return stoi(n);
        }
        
        return stoi(n);
    }
};