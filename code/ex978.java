class Solution {
    public int maxTurbulenceSize(int[] A) {
        int n = A.length;
        int[] up = new int[n];
        int[] down = new int[n];
        Arrays.fill(up, 1);
        Arrays.fill(down, 1);
        int max = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                up[i] = down[i - 1] + 1;
            else if (A[i] < A[i - 1])
                down[i] = up[i - 1] + 1;
            max = Math.max(max, Math.max(up[i], down[i]));
        }
        return max;
    }
}