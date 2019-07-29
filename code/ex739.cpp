// Monotone stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        
        vector<int> res(n, 0);
        stack<int> stk;    stk.push(0);
        
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        
        return res;
    }
};