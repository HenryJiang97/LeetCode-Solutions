class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int MAX = 0;
        
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            MAX = max(MAX, (hi - lo) * min(height[lo], height[hi]));
            if (height[lo] < height[hi])    lo++;
            else    hi--;
        }
        
        return MAX;
    }
};