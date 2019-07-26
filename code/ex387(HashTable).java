import java.util.*;

class Solution {
    public int firstUniqChar(String s) {
        Map<Character, List<Integer>> map = new HashMap<>();      
        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)))    map.get(s.charAt(i)).add(i);
            else    map.put(s.charAt(i), new ArrayList<Integer>(Arrays.asList(i)));
        }

        for (int i = 0; i < s.length(); i++) {
            if (map.get(s.charAt(i)).size() == 1)    return i;
        }

        return -1;
    }
}