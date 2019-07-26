// O(nlogn)

import java.util.*;

class Solution {
    public char findTheDifference(String s, String t) {
        char[] ca_s = s.toCharArray();
        char[] ca_t = t.toCharArray();
        Arrays.sort(ca_s);
        Arrays.sort(ca_t);
        
        for (int i = 0; i < ca_s.length; i++) {
            if (ca_s[i] != ca_t[i])
                return ca_t[i];
        }
    
        return ca_t[ca_t.length - 1];
    }
}