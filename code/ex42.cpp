class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> suffix(n);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = i == n - 1 ? 0 : max(suffix[i + 1], height[i + 1]);
        
        int res = 0, MAX = 0;
        for (int i = 0; i < n; i++) {
            res += max(0, min(MAX, suffix[i]) - height[i]);
            MAX = max(MAX, height[i]);
        }
        
        return res;
    }
};