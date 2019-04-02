class Solution {
    public boolean isSubsequence(String s, String t) {
        int ps = 0, pt = 0;
        
        while (pt < t.length() && ps < s.length()) {
            char cs = s.charAt(ps);
            char ct = t.charAt(pt);
            
            if (cs == ct) {
                ps++;
                pt++;
            } else
                pt++;
        }

        return (ps >= s.length()) ? true : false;
    }
}