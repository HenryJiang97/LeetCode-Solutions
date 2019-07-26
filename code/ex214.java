class Solution {
    public String shortestPalindrome(String s) {        
        int len = s.length();
        
        int end = len;
        int i = 0;
        int j = end - 1;
        
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;    j--;
            } else {
                i = 0;    end--;    j = end - 1;
            }
        }
        
        return new StringBuilder(s.substring(end, len)).reverse().toString() + s;
    }
}