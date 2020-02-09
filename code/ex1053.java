class Solution {
    public int[] prevPermOpt1(int[] A) {
        // Find the first element which violates the descending trend
        int _i = -1;
        for (int i = A.length - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                _i = i;
                break;
            }
        }
        if (_i == -1)    return A;
        
        // Find the closest num less than A[_i] after _i
        int _j = _i, minDiff = Integer.MAX_VALUE;
        for (int j = _i + 1; j < A.length; j++) {
            if (A[j] < A[_i] && A[_i] - A[j] < minDiff) {
                minDiff = A[_i] - A[j];
                _j = j;
            }   
        }
        
        // Swap
        int temp = A[_i];
        A[_i] = A[_j];
        A[_j] = temp;
        
        return A;
    }
}