class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int[] array1 = new int[7];
        int[] array2 = new int[7];
        int[] same = new int[7];       
        
        // Get the appearence time for each diece
        for (int i = 0; i < A.length; i++) {
            array1[A[i]]++;
            array2[B[i]]++;
            if (A[i] == B[i])    same[A[i]]++;
        }
        
        // Find which diece appears the most
        int max = 0, maxIndex = 0;
        for (int i = 0; i < 7; i++) {
            if (array1[i] + array2[i] - same[i] > max) {        
                max = array1[i] + array2[i] - same[i];
                maxIndex = i;
            }
        }

        if (max < A.length)    return -1;
        
        // Get the larger appearence time
        int app1 = 0, app2 = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] == maxIndex)    app1++;
            if (B[i] == maxIndex)    app2++;
        }
        
        int app = Math.min(app1, app2);

        
        return app - same[maxIndex];
    }
}