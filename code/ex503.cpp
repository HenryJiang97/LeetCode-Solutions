class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)    nums.push_back(nums[i]);
        n *= 2;
        
        stack<int> stk;    // Monotonous decreasing
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i])
                stk.pop();
            res[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        
        res.resize(n / 2);
        return res;
    }
};