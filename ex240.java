// Brute Force (BS)
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int[] row : matrix)
            if (Arrays.binarySearch(row, target) >= 0)    return true;
        return false;
    }
}