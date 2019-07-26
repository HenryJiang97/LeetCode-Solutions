import java.util.*;

class Solution {
    public void conquer(int[] nums, int lo, int mid, int hi) {
        int[] backup = Arrays.copyOf(nums, nums.length);
        int p1 = lo, p2 = mid + 1, p = lo;
        
        while (p <= hi) {
            if (p1 > mid)    nums[p++] = backup[p2++];
            else if (p2 > hi)    nums[p++] = backup[p1++];
            else if (backup[p1] > backup[p2])    nums[p++] = backup[p2++];
            else    nums[p++] = backup[p1++];
        }
    }
    
    public void mergeSort(int[] nums, int lo, int hi) {
        if (lo >= hi)    return;
        
        int mid = (lo + hi) / 2;
        
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        
        // Conquer
        conquer(nums, lo, mid, hi);
    }
    
    public int findKthLargest(int[] nums, int k) {
        mergeSort(nums, 0, nums.length - 1);
        
        return nums[nums.length - k];
    }
}