// DFS

class Solution {   
    public static boolean DFS(String s1, String s2, String s3, int p1, int p2) {
        int p3 = p1 + p2;
        
        // If one pointer reaches the end
        if (p1 == s1.length())
            return s2.substring(p2, s2.length()).equals(s3.substring(p3, s3.length()));
        if (p2 == s2.length())
            return s1.substring(p1, s1.length()).equals(s3.substring(p3, s3.length()));
        
        
        boolean result = false;
        // Match next char in s1
        if (s1.charAt(p1) == s3.charAt(p3))
            result = result || DFS(s1, s2, s3, p1 + 1, p2);
        
        // Match next char in s2
        if (s2.charAt(p2) == s3.charAt(p3))
            result = result || DFS(s1, s2, s3, p1, p2 + 1);
        
        return result;
    }
    
    public boolean isInterleave(String s1, String s2, String s3) {
        return DFS(s1, s2, s3, 0, 0);
    }
}