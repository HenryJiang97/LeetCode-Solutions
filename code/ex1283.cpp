class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = INT_MAX;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (valid(nums, threshold, mid))    hi = mid;
            else    lo = mid + 1;
        }
        return hi;
    }
    
private:
    bool valid(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;
        for (int num : nums)    sum += ceil((double)num / divisor);
        return sum <= threshold;
    }
};