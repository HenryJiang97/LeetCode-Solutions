// Binary Search

class Solution {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        int first = nums[0], last = nums[n - 1];
        
        if (k > last - (first + n - 1)) {    // The k-th missing number is larger than the last element
            return k - (last - (first + n - 1)) + last;
        }
        else {
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                int missing = getMissing(nums, mid);
                if (missing < k)    lo = mid + 1;
                else    hi = mid;
            }
            return nums[hi - 1] + (k - getMissing(nums, hi - 1));
        }
    }
    
    private int getMissing(int[] nums, int k) {
        return nums[k] - (nums[0] + k);
    }
}