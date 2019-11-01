// Two pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i])    continue;    // Skip duplicates
            int lo = i + 1, hi = n - 1;
            int target = -nums[i];
            
            while (lo < hi) {    // Use two pointers to find the other two numbers
                if (nums[lo] + nums[hi] == target) {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    // Skip duplicates
                    while (lo < hi && nums[lo + 1] == nums[lo])    lo++;
                    while (lo < hi && nums[hi - 1] == nums[hi])    hi--;
                    lo++;    hi--;
                }
                else if (nums[lo] + nums[hi] < target) {
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }
        
        return res;
    }
};