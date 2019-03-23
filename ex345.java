import java.util.*;

class Solution {
    public boolean isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    
    
    public String reverseVowels(String s) {
        StringBuilder sb = new StringBuilder(s);
        
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            char s_lo = sb.charAt(lo);
            char s_hi = sb.charAt(hi);
            
            if (isVowel(s_lo) && isVowel(s_hi)) {
                sb.setCharAt(lo, s_hi);
                sb.setCharAt(hi, s_lo);
                lo++;    hi--;
            }
            else if (isVowel(s_lo))
                hi--;
            else if (isVowel(s_hi))
                lo++;
            else {
                lo++;    hi--;
            }
        }
        
        return sb.toString();
    }
}