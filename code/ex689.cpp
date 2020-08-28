class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> prefix{0};
        for (int i = 0; i < n; i++)    prefix.push_back(prefix.back() + nums[i]);
        
        // Get indexes of left and right two subarrays with maximum sum
        vector<int> l(n, 0), r(n, n - k);
        int MAX = 0;
        for (int i = k - 1; i < n; i++) {
            if (prefix[i + 1] - prefix[i - k + 1] > MAX) {
                MAX = prefix[i + 1] - prefix[i - k + 1];
                l[i] = i - k + 1;
            } else {
                l[i] = l[i - 1];
            }
        }
        
        MAX = 0;
        for (int i = n - k; i >= 0; i--) {
            if (prefix[i + k] - prefix[i] >= MAX) {
                MAX = prefix[i + k] - prefix[i];
                r[i] = i;
            } else {
                r[i] = r[i + 1];
            }
        }
        
        // Get the middle subarray
        MAX = 0;
        vector<int> res = {};
        for (int i = k; i <= n - k * 2; i++) {
            int left = prefix[l[i - 1] + k] - prefix[l[i - 1]];
            int right = prefix[r[i + k] + k] - prefix[r[i + k]];
            int mid = prefix[i + k] - prefix[i];
            if (left + right + mid > MAX) {
                MAX = left + right + mid;
                res = {l[i - 1], i, r[i + k]};
            }
        }
        
        return res;
    }
};