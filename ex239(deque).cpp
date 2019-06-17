// Deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0)    return {};
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        
        for (int i = 0; i < n; i++) {
            // Add index to the back of deque
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            // Trim head
            while (dq.front() <= i - k)
                dq.pop_front();
            
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};