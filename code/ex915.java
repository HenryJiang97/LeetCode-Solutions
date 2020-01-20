class Solution {
    public int partitionDisjoint(int[] A) {
        int n = A.length;
        int[] left = new int[n], right = new int[n];
        for (int i = 0; i < n; i++)
            left[i] = i == 0 ? A[i] : Math.max(left[i - 1], A[i]);
        for (int i = n - 1; i >= 0; i--)
            right[i] = i == n - 1 ? A[i] : Math.min(right[i + 1], A[i]);
        for (int i = 0; i < n - 1; i++)
            if (left[i] <= right[i + 1])    return i + 1;
        return 0;
    }
}