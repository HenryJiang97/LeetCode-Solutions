// Seperate the nums array into several sections with each section has length of k
// Maintain two max_arrays: max_left, max_right
// max_left[i] => max number to the left part in the corresponding section
// max_right[i] => max number to the right part in the corresponding section

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0)    return vector<int>(0);
        int n = nums.size();
        
        auto max_left = vector<int>(n), max_right = vector<int>(n);
        max_left[0] = nums[0];    max_right[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            // Maintain max_left
            if (i % k == 0)    max_left[i] = nums[i];
            else    max_left[i] = max(max_left[i - 1], nums[i]);
            // Maintain max_right
            int j = n - 1 - i;
            if (j % k == 0)    max_right[j] = nums[j];
            else    max_right[j] = max(max_right[j + 1], nums[j]);
        }
        
        vector<int> res(n - k + 1);
        for (int i = 0; i <= n - k; i++)
            res[i] = max(max_right[i], max_left[i + k - 1]);
        return res;
    }
};