class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {    // O(n^3)
        int m = nums1.length, n = nums2.length;
        int[] res = new int[k];
        
        // Loop through every possible length for nums from nums1
        for (int l = Math.max(0, k - n); l <= k && l <= m; l++) {
            int[] newRes = merge(maxArray(nums1, l), maxArray(nums2, k - l));
            if (isGreater(newRes, 0, res, 0))    res = newRes;
        }
        
        return res;
    }
    
    private int[] merge(int[] nums1, int[] nums2) {    // O(n)
        int m = nums1.length, n = nums2.length;
        int[] res = new int[m + n];
        int p1 = 0, p2 = 0, p = 0;
        while (p1 < m || p2 < n) {
            res[p++] = isGreater(nums1, p1, nums2, p2) ? nums1[p1++] : nums2[p2++];
        }
        return res;
    }
    
    private boolean isGreater(int[] nums1, int p1, int[] nums2, int p2) {    // O(n)
        int m = nums1.length, n = nums2.length;
        while (p1 < m && p2 < n && nums1[p1] == nums2[p2]) {
            p1++;    p2++;
        }
        if (p2 == n)    return true;
        if (p1 == m)    return false;
        return nums1[p1] > nums2[p2];
    }
    
    private int[] maxArray(int[] arr, int len) {    // O(n)
        int n = arr.length;
        
        Stack<Integer> stack = new Stack<>();    // Maintain a monotone stack
        for (int i = 0; i < n; i++) {
            int a = arr[i];
            while (!stack.isEmpty() && stack.size() + arr.length - i > len && stack.peek() < a)
                stack.pop();
            if (stack.size() < len)
                stack.push(a);
        }
        
        int[] newArr = new int[len];
        for (int i = len - 1; i >= 0; i--)
            newArr[i] = stack.pop();
        return newArr;
    }
}