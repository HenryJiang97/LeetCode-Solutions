class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        // Reverse the char array
        reverse(s, 0, n - 1);
        
        // Reverse each word
        int slow = 0, fast = 0;
        while (fast < n) {
            if (s[fast] == ' ') {
                reverse(s, slow, fast - 1);
                slow = fast + 1;
            }
            fast++;
        }
        reverse(s, slow, n - 1);
    }
    
    private void reverse(char[] s, int lo, int hi) {
        while (lo < hi) {
            char temp = s[lo];
            s[lo++] = s[hi];
            s[hi--] = temp;
        }
    }
}