import java.util.*;

class Solution {
    public int thirdMax(int[] nums) {
        long[] max = new long[3];
        Arrays.fill(max, Long.MIN_VALUE);
        
        for (int i : nums) {
            if (i == max[0] || i == max[1] || i == max[2])    continue;
            
            if (i > max[0]) {
                max[2] = max[1];
                max[1] = max[0];
                max[0] = i;
            } else if (i > max[1]) {
                max[2] = max[1];
                max[1] = i;
            } else if (i > max[2]) {
                max[2] = i;
            }
        }
        
        return max[2] == Long.MIN_VALUE ? (int)max[0] : (int)max[2];
    }
}