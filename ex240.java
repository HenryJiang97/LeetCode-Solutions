class Solution {
    private static boolean binarySearch(int[] m, int target, int lo, int hi) {
        if (lo > hi)
            return false;

        int mid = (lo + hi) / 2;


        if (target > m[mid])
            return binarySearch(m, target, mid + 1, hi);

        else if (target < m[mid])
            return binarySearch(m, target, lo, mid - 1);

        else
            return true;
    }
    
    public boolean searchMatrix(int[][] matrix, int target) {
        boolean result = false;
        
        for (int i = 0; i < matrix.length; i++) {
            if (binarySearch(matrix[i], target, 0, matrix[i].length - 1) == true) {
                result = true;
                break;
            }
        }
        
        return result;
    }
}