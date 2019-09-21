class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;    if (n == 0)    return new int[][]{};
        
        Arrays.sort(intervals, (a, b)->a[0] - b[0]);    // Sort by starting time of interval
        
        List<int[]> r = new ArrayList<>();
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= end) {    // Has interval
                end = Math.max(end, intervals[i][1]);
            }
            else {    // Non-overlapping
                r.add(new int[]{start, end});
                start = intervals[i][0];    end = intervals[i][1];
            }
        }
        r.add(new int[]{start, end});
        
        
        // Transfer to array
        int[][] res = new int[r.size()][2];
        for (int i = 0; i < res.length; i++) {
            res[i] = r.get(i);
        }
        
        return res;
    }
}