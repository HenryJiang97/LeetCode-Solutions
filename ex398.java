// Reservior Sampling

import java.util.*;

class Solution {
    Random rand;
    int[] arr;

    public Solution(int[] nums) {
        rand = new Random();
        arr = nums;
    }
    
    public int pick(int target) {
        int count = 0, result = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != target)    continue;
            
            count++;
            // Get random number to judge if to change result
            if (rand.nextInt(count) + 1 == count)
                result = i;
        }
        
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */