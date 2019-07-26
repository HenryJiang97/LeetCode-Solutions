// Sort these people by the money the company can save,
// if ask that person to go to city A instead of city B

import java.util.*;

class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return (b[1] - b[0]) - (a[1] - a[0]) ;
            }
        });
        
        int res = 0;
        for (int i = 0; i < costs.length / 2; i++) {
            res = res + costs[i][0] + costs[costs.length - 1 - i][1];
        }
        
        return res;
    }
}