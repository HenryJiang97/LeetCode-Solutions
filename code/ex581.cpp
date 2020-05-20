class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = -1;
        int MAX = INT_MIN, MIN = INT_MAX;
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, nums[i]);
            MIN = min(MIN, nums[n - i - 1]);
            if (MAX > nums[i])    hi = i;
            if (MIN < nums[n - i - 1])    lo = n - i - 1;
        }
        
        return hi - lo + 1;
    }
};