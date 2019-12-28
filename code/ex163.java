class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        int n = nums.length;
        List<String> res = new ArrayList<>();
        
        // No num in the array
        if (n == 0) {
            if (upper - lower == 0)
                res.add(String.valueOf(lower));
            else {
                res.add(String.valueOf(lower) + "->" + String.valueOf(upper));
            }
            return res;
        }
        
        // Get lo and hi index
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < lower)    continue;
            if (nums[i] > upper)    break;
            if (i >= 1 && nums[i - 1] < lower)    lo = i;
            hi = i;
        }
        
        if (nums[lo] != lower) {
            if (nums[lo] == lower + 1)
                res.add(String.valueOf(lower));
            else
                res.add(String.valueOf(lower) + "->" + String.valueOf(nums[lo] - 1));
        }
        
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] == nums[i - 1] || nums[i] - 2 < nums[i - 1])
                continue;
            else if (nums[i] - 2 == nums[i - 1])
                res.add(String.valueOf(nums[i] - 1));
            else
                res.add(String.valueOf(nums[i - 1] + 1) + "->" + String.valueOf(nums[i] - 1));
        }
        
        if (nums[hi] != upper) {
            if (nums[hi] == upper - 1)
                res.add(String.valueOf(upper));
            else
                res.add(String.valueOf(nums[hi] + 1) + "->" + String.valueOf(upper));
        }
        
        return res;
    }
}