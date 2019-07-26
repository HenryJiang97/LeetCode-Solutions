class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        int start = newInterval[0], end = newInterval[1];
        
        List<int[]> list = new ArrayList<>();
        
        int p = 0;
        // Add intervals before newInterval to the list
        while (p < n && intervals[p][1] < start)
            list.add(intervals[p++]);
        
        // Merge newInterval with overlapping intervals
        while (p < n && intervals[p][0] <= end) {
            newInterval[0] = Math.min(intervals[p][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[p][1], newInterval[1]);
            p++;
        }
        list.add(newInterval);
        
        // Add intervals after newInterval to the list
        while (p < n)
            list.add(intervals[p++]);
        
        
        // Copy list to array
        int[][] res = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            res[i][0] = list.get(i)[0];
            res[i][1] = list.get(i)[1];
        }
        
        return res;
    }
}