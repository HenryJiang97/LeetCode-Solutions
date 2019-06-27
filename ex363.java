// TreeMap

class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length;    if (m == 0)    return 0;
        int n = matrix[0].length;    if (n == 0)    return 0;
        
        int max = Integer.MIN_VALUE;
        // Loop through the column
        for (int c1 = 0; c1 < n; c1++) {    // c1 and c2 are two pointers moving along the column
            int[] rowSum = new int[m];
            for (int c2 = c1; c2 < n; c2++) {
                // Get the sum for each row
                for (int r = 0; r < m; r++)
                    rowSum[r] += matrix[r][c2];
                
                // Using a treeset to reduce 4 loops to 3
                TreeSet<Integer> set = new TreeSet<>();
                int sum = 0;
                set.add(sum);
                
                for (int r = 0; r < m; r++) {
                    sum += rowSum[r];
                    Integer ceiling = set.ceiling(sum - k);
                    if (ceiling != null)    max = Math.max(max, sum - ceiling);
                    set.add(sum);
                }
            }
        }
        
        return max;
    }
}