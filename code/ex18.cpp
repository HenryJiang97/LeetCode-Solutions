class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();    if (n < 4)    return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])    continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])    continue;
                int a = nums[i], b = nums[j];
                int t = target - a - b;
                if (nums[j + 1] + nums[j + 2] > t)    continue;
                
                // Two pointers for t
                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    while (lo > j + 1 && nums[lo] == nums[lo - 1] && lo < hi)    lo++;
                    while (hi < n - 1 && nums[hi] == nums[hi + 1] && lo < hi)    hi--;
                    if (lo >= hi)    continue;
                    int c = nums[lo], d = nums[hi];
                    if (c + d == t)    {res.push_back({a, b, c, d});    lo++;    hi--;}
                    else if (c + d > t)    hi--;
                    else    lo++;
                }   
            }
        }
        
        return res;
    }
};