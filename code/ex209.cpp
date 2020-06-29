class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = 0, sum = 0, MIN = INT_MAX;
        while (hi < n) {
            sum += nums[hi];
            while (sum >= s) {
                MIN = min(MIN, hi - lo + 1);
                sum -= nums[lo++];
            }
            hi++;
        }
        
        return MIN == INT_MAX ? 0 : MIN;
    }
};