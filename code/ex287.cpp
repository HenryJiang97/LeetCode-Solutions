class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            if (bs(nums, i + 1, n - 1, t))
                return t;
        }
        
        return 0;
    }
    
private:
    bool bs(vector<int>& nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return 1;
            else if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return 0;
    }
};