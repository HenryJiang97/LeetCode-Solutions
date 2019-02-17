// Brute Force

class Solution {
    public static int dp(String s, String t, int ps, int pt, int counter) {
        // System.out.println(ps);
        // System.out.println(pt);
        // System.out.println(counter);
        // System.out.println();
        
        
        if (pt == t.length() - 1 && s.charAt(ps) == t.charAt(pt)) {
            counter++;
            return counter;
        }
        
        if (ps >= s.length())    return counter;
        
        if (s.charAt(ps) != t.charAt(pt))    return counter;
        
        for (int i = ps + 1; i < s.length(); i++) {
            counter = dp(s, t, i, pt + 1, counter);
        }
        
        return  counter;
    }
    
    
    public int numDistinct(String s, String t) {
        if (t.length() == 0)    return 1;
        
        int counter = 0;
        
        for (int i = 0; i < s.length(); i++) {
            counter = dp(s, t, i, 0, counter);
        }
        
        return counter;
    }
}