class Solution {
    public boolean isIdealPermutation(int[] A) {
        int n = A.length;
        int[] min = new int[n];    // The minimum num after i
        min[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            min[i] = Math.min(min[i + 1], A[i]);
        
        for (int i = 0; i < n - 2; i++) {    // Judge if there are global inversions in the array
            if (min[i + 2] < A[i])    return false;
        }
        
        return true;
    }
}