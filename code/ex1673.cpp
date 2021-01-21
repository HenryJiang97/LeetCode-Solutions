class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() > nums[i] && (n - i + stk.size() - 1) >= k) {
                stk.pop();
            }
            if (stk.size() < k)    stk.push(nums[i]);
        }
        
        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};