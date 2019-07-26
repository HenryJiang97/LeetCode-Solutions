class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        if (A.length == 0)    return 0;
        
        for (int i = 0; i < K; i++) {
            int minIndex = 0;
            for (int j = 0; j < A.length; j++) {
                if (A[j] < A[minIndex])    minIndex = j;
            }
            A[minIndex] = -A[minIndex];
        }
        
        int sum = 0;
        for (int i : A) {
            sum += i;
        }
        
        return sum;
    }
}