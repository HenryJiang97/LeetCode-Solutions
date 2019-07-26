import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, Integer> map = new HashMap<>();
        String s[] = str.split(" ");    // Convert str into a string array

        // If pattern and string have different length, it cannot be true
        if (pattern.length() != s.length)   return false;

        // Traverse through each character in pattern
        for (int i = 0; i < pattern.length(); i++) {
            if (!map.containsKey(pattern.charAt(i))) {
                // If two char in pattern are different,
                // their corresponding string cannot be the same
                for (Character c : map.keySet())
                    if (s[i].equals(s[map.get(c)]))
                        return false;

                // Create a new key in the map and add the position to the map
                map.put(pattern.charAt(i), i);
            } else {
                // Check 
                if (!s[i].equals(s[map.get(pattern.charAt(i))]))
                    return false;
            }
        }

        return true;
    }
}