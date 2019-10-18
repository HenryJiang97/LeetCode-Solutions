class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> res;
        
        // Find the first index
        int lo = 0, hi = n - 1, t = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                if (mid - 1 < 0 || nums[mid - 1] < target) {
                    t = mid;
                    break;
                }
                hi = mid - 1;
            }
            else if (nums[mid] > target)    hi = mid - 1;
            else    lo = mid + 1;
        }
        res.push_back(t);
        
        // Find the second index
        lo = 0; hi = n - 1; t = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                if (mid + 1 >= n || nums[mid + 1] > target){
                    t = mid;
                    break;
                }
                lo = mid + 1;
            }
            else if (nums[mid] < target)    lo = mid + 1;
            else    hi = mid - 1;
        }
        res.push_back(t);
        
        return res;
    }
};