import java.util.HashMap;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0, lower = -1;
        HashMap<Character, Integer> map = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), i);
                max = Math.max(max, i - Math.max(lower, -1));
            } else {
                max = Math.max(max, i - Math.max(map.get(s.charAt(i)), lower));
                // lower is to record the position of last duplicated char
                lower = Math.max(map.get(s.charAt(i)), lower);
                map.put(s.charAt(i), i);
            }
        }
        
        return max;
    }
}