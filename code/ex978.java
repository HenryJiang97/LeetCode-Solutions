class Solution {
    public int maxTurbulenceSize(int[] A) {
        int n = A.length;
        int max = 1, up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                up = down + 1;
                down = 1;
            }
            else if (A[i] < A[i - 1]) {
                down = up + 1;
                up = 1;
            } else {
                down = 1;
                up = 1;
            }
            max = Math.max(max, Math.max(up, down));
        }
        return max;
    }
}