class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        
        boolean seenNumbers = false;
        boolean seenDecimals = false;
        boolean seenE = false;
        boolean numberAfterE = true;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                seenNumbers = true;
                numberAfterE = true;
            }
            else if (c == '.') {
                if (seenDecimals || seenE)    return false;
                seenDecimals = true;
            }
            else if (c == 'e') {
                if (seenE || !seenNumbers)    return false;
                numberAfterE = false;
                seenE = true;
            }
            else if (c == '+' || c == '-') {
                if (i != 0 && s.charAt(i - 1) != 'e')
                    return false;
            }
            else {
                return false;
            }
        }
        
        return seenNumbers && numberAfterE;
    }
}