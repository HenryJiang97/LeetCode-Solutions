// Hash Table DP
// Build a dp map to store the possible k at each stone

import java.util.*;

class Solution {
    public boolean canCross(int[] stones) {
        // Corner case
        if (stones.length == 0)    return false;
        if (stones.length == 1)    return true;
        
        Map<Integer, Set<Integer>> map = new HashMap<>();
        Character.tochar
        for (int i = 0; i < stones.length; i++) {
            map.put(stones[i], new HashSet<Integer>());
        }
        if (map.containsKey(stones[0] + 1))
            map.get(stones[0] + 1).add(1);
        else
            return false;
        
        
        for (int i = 1; i < stones.length; i++) {
            Set<Integer> set = map.get(stones[i]);

            for (int k : set) {
                if (map.containsKey(stones[i] + k - 1) && k - 1 != 0)    map.get(stones[i] + k - 1).add(k - 1);
                if (map.containsKey(stones[i] + k))    map.get(stones[i] + k).add(k);
                if (map.containsKey(stones[i] + k + 1))    map.get(stones[i] + k + 1).add(k + 1);
            }
        }     
        
        return map.get(stones[stones.length - 1]).size() == 0 ? false : true;
    }
}