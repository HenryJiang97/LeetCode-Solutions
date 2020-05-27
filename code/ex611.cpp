class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] + nums[j] <= nums[j + 1])    continue;
                cnt += bs(nums, nums[i] + nums[j], j + 1);
            }
        }
        return cnt;
    }
    
private:
    int bs(vector<int>& nums, int target, int start) {
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (nums[mid] < target)    lo = mid;
            else    hi = mid - 1;
        }
        return lo - start + 1;
    }
};