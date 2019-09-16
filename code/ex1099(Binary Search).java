// Binary Search

class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int n = A.length;
        Arrays.sort(A);
        
        int max = -1;
        for (int i = 0; i < n - 1; i++) {
            int second = K - A[i];
            
            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (A[mid] >= second) {
                    hi = mid - 1;
                }
                else {
                    if (mid + 1 >= n || A[mid + 1] >= second) {
                        max = Math.max(max, A[i] + A[mid]);
                        break;
                    }
                    lo = mid + 1;
                }
            }
        }
        
        return max;
    }
}