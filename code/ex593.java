class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int pinf = Integer.MAX_VALUE, ninf = Integer.MIN_VALUE;
        int[][] points = new int[][]{{p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
        
        // Sort four points by x-corrdinate
        Arrays.sort(points, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        
        // Judge if the two diagonoses are palindrome
        double k1 = (double)(points[3][1] - points[0][1]) / (points[3][0] - points[0][0]);
        double k2 = (double)(points[2][1] - points[1][1]) / (points[2][0] - points[1][0]);
        
        if ((points[3][0] - points[0][0] == 0) && k2 != 0.0)    return false;
        else if ((points[2][0] - points[1][0] == 0) && k1 != 0.0)    return false;
        if ((points[3][0] - points[0][0] != 0 && points[2][0] - points[1][0] != 0) && Math.abs(k1 * k2 + 1.0) > 1e-4)    return false;

        // Judge if the two diagonoses have the same length
        if (((points[3][1] - points[0][1]) * (points[3][1] - points[0][1]) + (points[3][0] - points[0][0]) * (points[3][0] - points[0][0])) != ((points[2][1] - points[1][1]) * (points[2][1] - points[1][1]) + (points[2][0] - points[1][0]) * (points[2][0] - points[1][0])))    return false;
        
        // Judge if the two diagonoses have the same mid-point
        if ((points[0][0] + points[3][0] != points[1][0] + points[2][0]) || (points[0][1] + points[3][1] != points[1][1] + points[2][1]))    return false;
        
        return true;
    }
}