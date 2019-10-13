// Binary search

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        int left = (n1 + n2 + 1) / 2, right = (n1 + n2 + 2) / 2;
        return (double)(findKth(nums1, nums2, 0, 0, left) + findKth(nums1, nums2, 0, 0, right)) / 2;
    }
    
    private double findKth(int[] nums1, int[] nums2, int p1, int p2, int k) {
        if (p1 >= nums1.length)    return nums2[p2 + k - 1];
        if (p2 >= nums2.length)    return nums1[p1 + k - 1];
        if (k == 1)    return Math.min(nums1[p1], nums2[p2]);
        
        int mid1 = (p1 + k / 2 - 1) < nums1.length ? nums1[p1 + k / 2 - 1] : Integer.MAX_VALUE;
        int mid2 = (p2 + k / 2 - 1) < nums2.length ? nums2[p2 + k / 2 - 1] : Integer.MAX_VALUE;
        
        if (mid1 < mid2) {
            return findKth(nums1, nums2, p1 + k / 2, p2, k - k / 2);
        } else {
            return findKth(nums1, nums2, p1, p2 + k / 2, k - k / 2);
        }
    }
    
}