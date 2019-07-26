class Solution {
    public String licenseKeyFormatting(String S, int K) {
        StringBuilder sb = new StringBuilder();
        
        int p = S.length() - 1;
        while (p >= 0) {
            for (int i = 0; i < K && p >= 0; i++) {
                char c = S.charAt(p--);
                if (c == '-')    {i--;}
                else if (c >= 97 && c <= 122)    sb.append(Character.toString((char)(c - 32)));
                else    sb.append(Character.toString(c));
            }
            sb.append("-");
        }
        
        // Remove - from the end part of the string
        while (sb.length() > 0 && sb.charAt(sb.length() - 1) == '-')    sb.deleteCharAt(sb.length() - 1);
        return sb.reverse().toString();
    }
}