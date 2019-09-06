class Solution {
    public int search(ArrayReader reader, int target) {
        int max = 2147483647;
        if (reader.get(0) == max)    return -1;
        
        // Find the end point of the array
        int lo = 0, hi = Integer.MAX_VALUE;
        int end = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (reader.get(mid) == max) {
                if (reader.get(mid - 1) != max) {
                    end = mid - 1;
                    break;
                } else {
                    hi = mid - 1;
                }
            } else {
                lo = mid + 1;
            }
        }
        
        // Find the target
        lo = 0; hi = end;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (reader.get(mid) == target)    return mid;
            else if (reader.get(mid) > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return -1;
    }
}