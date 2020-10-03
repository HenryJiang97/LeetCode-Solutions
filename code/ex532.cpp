class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            int target = nums[i] + k, lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] == target) {
                    cnt++;
                    break;
                }
                else if (nums[mid] < target)    lo = mid + 1;
                else    hi = mid - 1;
            }
        }
        return cnt;
    }
};