class Solution {
    public int minFlipsMonoIncr(String S) {
        int n = S.length();
        int[] left = new int[n];    // 1s before index i
        int[] right = new int[n];    // 0s after index i
        
        for (int i = 0; i < n; i++) {
            if (i == 0)    left[i] = S.charAt(i) - '0';
            else    left[i] = left[i - 1] + (S.charAt(i) - '0');
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1)    right[i] = S.charAt(i) == '0' ? 1 : 0;
            else    right[i] = right[i + 1] + (S.charAt(i) == '0' ? 1 : 0);
        }
        
        int min = n;
        for (int i = 0; i < n - 1; i++)
            min = Math.min(min, left[i] + right[i + 1]);
        return Math.min(min, Math.min(left[n - 1], right[0]));
    }
}