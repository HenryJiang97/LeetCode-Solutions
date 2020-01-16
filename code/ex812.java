class Solution {
    public double largestTriangleArea(int[][] points) {
        int n = points.length;
        double max = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    max = Math.max(max, calArea(points[i], points[j], points[k]));
                }
            }
        }
        return max;
    }
    
    private double calArea(int[] A, int[] B, int[] C) {
        return 0.5 * Math.abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - A[1] * B[0] - B[1] * C[0] - C[1] * A[0]);
    }
}