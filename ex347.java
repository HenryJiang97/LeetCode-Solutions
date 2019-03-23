import java.util.*;

class Solution {  
    public List<Integer> topKFrequent(int[] nums, int k) {
        // Build hash table
        Map<Integer, Integer> hash = new HashMap<>();
        for (int num : nums)    hash.put(num, hash.getOrDefault(num, 0) + 1);
        
        // Get results
        List<Integer> res = new ArrayList<>();

        for (Map.Entry<Integer, Integer> entry : hash.entrySet()) {
            res.add(entry.getKey());
        }
        
        res.sort((a, b) -> hash.get(b) - hash.get(a));       
        
        return res.subList(0, k);
    }
}