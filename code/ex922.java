class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int n = A.length;
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (A[i] % 2 == i % 2)    continue;
            
            while (A[j] % 2 != i % 2)    j += 2;
            // Swap A[i] with A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        return A;
    }
}