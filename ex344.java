// Solution 1
class Solution {
    public void reverseString(char[] s) {
        String rev_s = new StringBuilder(String.valueOf(s)).reverse().toString();
        for (int i = 0; i < s.length; ++i)    s[i] = rev_s.charAt(i);
    }
}


// Solution 2
class Solution {
    public void reverseString(char[] s) {
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[s.length - i - 1];
            s[s.length - i - 1] = s[i];
            s[i] = temp;
        }
    }
}