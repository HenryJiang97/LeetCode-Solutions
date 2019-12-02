class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] res = new int[n];
        
        for (int[] booking : bookings) {
            res[booking[0] - 1] += booking[2];
            if (booking[1] < n)    res[booking[1]] -= booking[2];
        }
        for (int i = 0; i < n; i++)
            res[i] += i > 0 ? res[i - 1] : 0;
        
        return res;
    }
}