class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder sb = new StringBuilder(S);
        int lo = 0, hi = sb.length() - 1;
        while (lo < hi) {
            while (lo < hi && !Character.isAlphabetic(sb.charAt(lo)))
                lo++;
            while (lo < hi && !Character.isAlphabetic(sb.charAt(hi)))
                hi--;
            // Swap two chars
            char temp = sb.charAt(lo);
            sb.setCharAt(lo, sb.charAt(hi));
            sb.setCharAt(hi, temp);
            lo++;    hi--;
        }
        return sb.toString();
    }
}   