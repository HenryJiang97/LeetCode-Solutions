class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= 0)    hi = mid;
            else    lo = mid + 1;
        }
        lo = hi - 1;
        
        vector<int> res;
        while (lo >= 0 || hi < nums.size()) {
            if (lo < 0)    res.push_back(nums[hi] * nums[hi++]);
            else if (hi >= nums.size())    res.push_back(nums[lo] * nums[lo--]);
            else if (nums[lo] * nums[lo] < nums[hi] * nums[hi])    res.push_back(nums[lo] * nums[lo--]);
            else    res.push_back(nums[hi] * nums[hi++]);
        }
        
        return res;
    }
};