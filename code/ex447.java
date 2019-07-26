// Hash Table

import java.util.*;

class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        
        Map<Double, Integer> gap = new HashMap<>();
        
        for (int i = 0; i < points.length; i++) {
            // Build Hash Table
            for (int j = 0; j < points.length; j++) {   
                double distance = dis(points, i, j);
                gap.put(distance, gap.getOrDefault(distance, 0) + 1);
            }
            
            // Get pair number
            for (Map.Entry<Double, Integer> entry : gap.entrySet()) {
                if (entry.getValue() > 1.0) {
                    res += (pairNum(entry.getValue() - 1) * 2);
                }
            }
            
            gap.clear();
        }
        
        return res;
    }
    
    // Get the distance between two points
    private double dis(int[][] points, int i, int j) {
        return Math.sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
    }
    
    // Get the number of pairs one point has the same distance with
    private int pairNum(int n) {
        int cnt = 0;
        while (n >= 1)    cnt += (n--);
        return cnt;
    }
    
}