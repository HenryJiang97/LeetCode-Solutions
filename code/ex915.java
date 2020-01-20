class Solution {
    public int partitionDisjoint(int[] A) {
        int curMax = A[0], max = A[0], p = 0;
        for (int i = 1; i < A.length; i++) {
            if (A[i] < curMax) {
                p = i;
                curMax = max;
            }
            max = Math.max(max, A[i]);
        }
        return p + 1;
    }
}