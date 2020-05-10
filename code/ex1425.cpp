class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int MAX = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        
        deque<int> dque;    // Keep values in deque decreasing
        dque.push_back(0);
        
        for (int i = 1; i < n; i++) {
            while (!dque.empty() && i - dque.front() > k)
                dque.pop_front();
            
            dp[i] = max(nums[i], dp[dque.front()] + nums[i]);
            MAX = max(MAX, dp[i]);
            
            // Remove values on tail to keep deque decreasing
            while (!dque.empty() && dp[dque.back()] <= dp[i])
                dque.pop_back();
            dque.push_back(i);
        }
        
        return MAX;
    }
};