// Greedy

class Solution {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0)    return 0;
        
        Arrays.sort(points, (a, b) -> a[1] - b[1]);
        
        int cnt = 0;
        int r = points[0][1];
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] <= r)    continue;
            // Else
            cnt++;
            r = points[i][1];
        }
        
        return cnt + 1;    
    }
}