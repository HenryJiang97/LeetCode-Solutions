/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        
        // Find the summit index
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid + 1 < n && arr.get(mid) < arr.get(mid + 1))
                lo = mid + 1;
            else
                hi = mid;
        }
        int summit = hi;
        if (arr.get(summit) == target)    return summit;
        
        
        int res = n;
        // Find in the acending hill
        int left = upperbs(target, arr, 0, summit - 1);
        if (left != -1)    res = min(res, left);
        
        // Find in the descending hill
        int right = lowerbs(target, arr, summit + 1, n - 1);
        if (right != -1)    res = min(res, right);
        
        return res == n ? -1 : res;
    }
    
private:
    int upperbs(int target, MountainArray &arr, int lo, int hi) {
        int ret = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.get(mid) == target)    return mid;
            else if (arr.get(mid) < target)    lo = mid + 1;
            else    hi = mid - 1;
        }
        return ret;
    }
    
    int lowerbs(int target, MountainArray &arr, int lo, int hi) {
        int ret = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr.get(mid) == target)    return mid;
            else if (arr.get(mid) < target)    hi = mid - 1;
            else    lo = mid + 1;
        }
        return ret;
    }
};