class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        
        stack<pair<int, int>> stk;    // Monotonously increasing {val, idx}
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[i] < stk.top().first) {
                cnt += i - stk.top().second;
                stk.pop();
            }
            stk.push({nums[i], i});
        }
        
        // Tackle remaining pairs in the stack
        while (!stk.empty()) {
            cnt += n - stk.top().second;
            stk.pop();
        }
        
        return cnt;
    }
};