import java.util.*;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int[] hash = new int[nums.length + 1];
        
        for (int n : nums) {
            hash[n]++;
            if (hash[n] > 1)    res.add(n);
        }
        
        return res;
    }
}