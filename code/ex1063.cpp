class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        stack<pair<int, int>> stk;    // Monotonous increasing {val, idx}
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first > nums[i]) {
                cnt += i - stk.top().second;
                stk.pop();
            }
            stk.push(pair(nums[i], i));
        }
        while (!stk.empty()) {
            cnt += n - stk.top().second;
            stk.pop();
        }
        
        return cnt;
    }
};