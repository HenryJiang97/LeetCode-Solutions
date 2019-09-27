class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        
        String res = "";
        
        int i = 0, left = 0, right = 0;
        while (i < n) {
            left = i;    right = i;
           
            // Find the middle part of the palindrom
            while (right + 1 < n && s.charAt(right + 1) == s.charAt(right)) {
                right++;
            }
            
            i++;
            
            // Expand from both left and right sides to find the longest palindrom at this point
            while (left - 1 >= 0 && right + 1 < n && s.charAt(left - 1) == s.charAt(right + 1)) {
                left--;    right++;
            }
            
            if (right - left + 1 > res.length())
                res = s.substring(left, right + 1);
        }
        
        return res;
    }
}