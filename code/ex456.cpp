class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMin{nums[0]};
        for (int i = 1; i < n; i++)    prefixMin.push_back(min(prefixMin[i - 1], nums[i]));
        stack<int> stk;    // Decreasing
        for (int i = n - 1; i >= 1; i--) {
            int pMin = prefixMin[i - 1];
            while (!stk.empty() && stk.top() <= pMin)
                stk.pop();
            if (!stk.empty() && stk.top() < nums[i])
                return 1;
            stk.push(nums[i]);
        }
        return 0;
    }
};