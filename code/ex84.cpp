class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<pair<int, int>> stk;    // Monotonously increasing {val, idx}
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first > heights[i]) {
                auto prev = stk.top();    stk.pop();
                if (stk.size() == 0) {    // The smallest height before i
                    MAX = max(MAX, prev.first * i);
                } else {    // Get the width between i and the prev smaller height
                    auto pprev = stk.top();
                    MAX = max(MAX, prev.first * (i - pprev.second - 1));
                }
            }
            stk.push({heights[i], i});
        }
        
        // Tackle remaining pairs in the stack
        while (!stk.empty()) {
            auto prev = stk.top();    stk.pop();
            if (stk.size() == 0) {
                MAX = max(MAX, prev.first * n);
            } else {
                auto pprev = stk.top();
                MAX = max(MAX, prev.first * (n - pprev.second - 1));
            }
        }
        
        return MAX;
    }
};