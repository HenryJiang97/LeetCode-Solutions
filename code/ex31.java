// 1. From right to left, find the first num which violates ascending trend, note as A.
// 2. From right to left, find the first num which is larger than A, note as B.
// 3. Swap A with B.
// 4. Reverse the array to the right of A.

class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        
        // Find a
        int a = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                a = i;
                break;
            }
        }
        if (a == -1) {
            Arrays.sort(nums);
            return;
        }
        
        // Find b
        int b = -1;
        for (int i = n - 1; i > a; i--) {
            if (nums[i] > nums[a]) {
                b = i;
                break;
            }
        }
        if (b == -1)    return;
        
        // Swap A and B
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        
        // Reverse
        int lo = a + 1, hi = n - 1;
        while (lo < hi) {
            temp = nums[lo];
            nums[lo++] = nums[hi];
            nums[hi--] = temp;
        }
    }
}