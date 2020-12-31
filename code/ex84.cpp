class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(INT_MIN);
        int n = heights.size(), MAX = 0;
        stack<pair<int, int>> stk;    // Monotonously increasing
        for (int i = 0; i < n; i++) {
            int first = i;    // The first idx where heights[idx] >= heights[i]
            while (!stk.empty() && heights[i] < stk.top().first) {
                MAX = max(MAX, stk.top().first * (i - stk.top().second));
                first = min(first, stk.top().second);
                stk.pop();
            }
            stk.push({heights[i], first});
        }
        return MAX;
    }
};