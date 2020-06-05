class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();    if (n < 3)    return 0;
        
        vector<int> prefix(n);
        for (int i = 0; i < n; i++) {
            prefix[i] = i == 0 ? nums[i] : min(nums[i], prefix[i - 1]);
        }
        
        stack<int> stk;    // Decreasing
        stk.push(nums[n - 1]);
        for (int i = n - 2; i >= 1; i--) {
            int min_before = prefix[i - 1];
            while (!stk.empty() && stk.top() <= min_before)
                stk.pop();
            if (!stk.empty() && nums[i] > stk.top())    return 1;
            if (stk.empty() || nums[i] < stk.top())    stk.push(nums[i]);
        }
        
        return 0;
    }
};