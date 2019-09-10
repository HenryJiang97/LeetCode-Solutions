class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder(str);
        
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) >= 'A' && sb.charAt(i) <= 'Z') {
                sb.setCharAt(i, (char)(sb.charAt(i) + 32));
            }
        }
        
        return sb.toString();
    }
}