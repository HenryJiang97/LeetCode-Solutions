class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int res = 0, diff = INT_MAX;
        
        for (int i = 0; i < n - 2; i++) {
            int remain = target - nums[i];
            
            // Find two num whose sum is closest to ramain
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }
                if (nums[lo] + nums[hi] < remain)    lo++;
                else    hi--;
            }
        }
        
        return res;
    }
};