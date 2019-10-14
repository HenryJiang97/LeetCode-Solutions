// Binary Search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
    
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((mid + 1 >= n || nums[mid + 1] > nums[mid]) && (mid - 1 < 0 || nums[mid - 1] > nums[mid]))
                return nums[mid];
            else if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return -1;
    }
};