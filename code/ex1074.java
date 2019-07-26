// Map & prefix sum

class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length;    if (m == 0)    return 0;
        int n = matrix[0].length;    if (n == 0)    return 0;
        
        int cnt = 0;
        // Loop through the column
        for (int c1 = 0; c1 < n; c1++) {    // c1 and c2 are two pointers moving along the column
            int[] rowSum = new int[m];
            for (int c2 = c1; c2 < n; c2++) {
                // Get the sum for each row
                for (int r = 0; r < m; r++)
                    rowSum[r] += matrix[r][c2];
                
                // Use map to store former sums
                Map<Integer, Integer> map = new HashMap<>();
                map.put(0, 1);
                int sum = 0;
                for (int r = 0; r < m; r++) {
                    sum += rowSum[r];
                    if (map.containsKey(sum - target))    cnt += map.get(sum - target);
                    map.put(sum, map.getOrDefault(sum, 0) + 1);
                }
            }
        }
        
        return cnt;
    }
}