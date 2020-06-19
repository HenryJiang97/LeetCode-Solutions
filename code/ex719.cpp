class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Get the minimum distance
        int min_dis = nums[1] - nums[0];
        for (int i = 1; i < n; i++)
            min_dis = min(min_dis, nums[i] - nums[i - 1]);
        
        // Get the maximum distance
        int max_dis = nums.back() - nums[0];
        
        // Binary search for the k-th smallest distance among the pairs
        int lo = min_dis, hi = max_dis;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (getPairs(nums, mid) >= k)    hi = mid;
            else    lo = mid + 1;
        }
        
        return lo;
    }
    
private:
    int getPairs(vector<int>& nums, int dis) {    // Get the number of pairs with distance <= dis
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            cnt += getUpperBound(nums, nums[i] + dis, i + 1, n - 1) - i - 1;
        }
        return cnt;
    }
    
    int getUpperBound(vector<int>& nums, int target, int lo, int hi) {    // Get the max idx which nums[idx] <= target
        if (target >= nums.back())    return nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)    lo = mid + 1;
            else    hi = mid;
        }
        return lo;
    }
};