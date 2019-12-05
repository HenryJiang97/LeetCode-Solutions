class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        
        int idx = -1, sum = 0, min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            sum = sum + gas[i] - cost[i];
            if (sum < min) {
                idx = i;
                min = sum;
            }
        }
        if (sum < 0)    return -1;    // Cannot return whichever the start point is
        
        return idx + 1 < n ? idx + 1 : 0;
    }
}