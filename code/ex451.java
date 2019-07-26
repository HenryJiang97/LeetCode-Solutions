// Hash Table

import java.util.*;

class Solution {
    public String frequencySort(String s) {
        // Build hash table
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // Build result string
        StringBuilder sb = new StringBuilder();
        while (!map.isEmpty()) {
            Character cm = 'a';
            int m = 0;
            for (Map.Entry<Character, Integer> entry : map.entrySet()) {
                if (entry.getValue() > m) {
                    cm = entry.getKey();
                    m = entry.getValue();
                }
            }
            map.remove(cm);
            
            for (int i = 0; i < m; i++) {
                sb.append(Character.toString(cm));
            }
        }
        
        return sb.toString();
    }
}