// Maintain a set to determine duplicate chars
// If there are two same char exists during iteration, add 2 to result since they are symmetry

import java.util.*;

class Solution {
    public int longestPalindrome(String s) {
        int cnt = 0;
        
        Set<Character> set = new HashSet<>();
        
        for (char c : s.toCharArray()) {
            if (set.contains(c)) {
                cnt += 2;
                set.remove(c);
            } else
                set.add(c);
        }
        
        return set.isEmpty() ? cnt : cnt + 1;
    }
}