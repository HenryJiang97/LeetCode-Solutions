class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> suffix(n);    // The maximum height at or after i
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = i == n - 1 ? height[i] : max(suffix[i + 1], height[i]);
        
        // Maintain a monotone stack from the left to right
        stack<int> stk;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || stk.top() < height[i])    stk.push(height[i]);
            sum += max(0, min(stk.top(), suffix[i]) - height[i]);
        }
        
        return sum;
    }
};