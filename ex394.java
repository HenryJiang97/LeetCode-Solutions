class Solution {
    // Find the corresponding ']' to the start '['
    private int findEnd(String s, int start) {
        int open = 1;

        while (open != 0) {
            if (s.charAt(start) == '[')    open++;
            else if (s.charAt(start) == ']')    open--;
            start++;
        }
        
        return start - 1;
    }
    
    private String stringBuilder(String s) {
        String result = "";
        int i = 0, k = 0;      
        
        while (i < s.length()) {
            if (s.charAt(i) == '[') {
                // Find the start and end index of the substring inside [...]
                int start = i + 1;
                i = findEnd(s, start);
                
                String r = stringBuilder(s.substring(start, i));
                for (int counter = 0; counter < k; counter++) {result += r;}
            } else if (Character.isDigit(s.charAt(i))) {
                // Get the full repeating number
                int start = i;
                while (s.charAt(i) != '[')    i++;
                k = Integer.parseInt(s.substring(start, i--));
            } else if (Character.isLetter(s.charAt(i)))
                result += Character.toString(s.charAt(i));

            i++;
        }
        
        return result;
    }
    
    public String decodeString(String s) {
        return stringBuilder(s);
    }
}