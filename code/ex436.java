class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        
        // Get a ordered group of {index, starting point val} pairs
        int[][] start = new int[n][2];
        for (int i = 0; i < n; i++) {
            start[i][0] = i;
            start[i][1] = intervals[i][0];
        }
        Arrays.sort(start, (a, b) -> a[1] - b[1]);
        
        // Run a binary search for each interval to find out the num of right intervals
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            if (start[n - 1][1] < intervals[i][1])    ret[i] = -1;
            else    ret[i] = BS(start, intervals[i][1]);
        }
        
        return ret;
    }
    
    // Search for the first index which is equal or larger than target
    private int BS(int[][] start, int target) {
        int lo = 0, hi = start.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (start[mid][1] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return start[hi][0];
    }
}