class Solution {
    public String longestPalindrome(String s) {
        // Special situation
        if (s.length() == 0 || s.length() == 1)
            return s;
        
        int max_len = 1;
        int start_pos = 0;
        
        // Loop throught the string
        int i = 0;
        while (i < s.length()) {
            int left = i;
            int right = i;
            
            // Loop to locate the right bound of the middle part of a potential palindromic
            // Beware that the middle part of a palindromic string might be the same
            while (right < s.length() - 1 && s.charAt(right) == s.charAt(right + 1))      right++;
            
            i = right + 1;
            
            // Find the left and right bound of the palindromic
            while (left > 0 && right < s.length() - 1 && s.charAt(left - 1) == s.charAt(right + 1)) {
                left--;
                right++;
            }
            
            // Record max length and the start, end position
            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
                start_pos = left;
            }

        }
        
        return s.substring(start_pos, start_pos + max_len);
    }
}