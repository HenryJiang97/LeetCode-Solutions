class Solution {
    public int compress(char[] chars) {       
        int start = 0;    // Pointer to track the head of new array
        char former = chars[0];
        int cnt = 0;
        
        for (char c : chars) {
            if (c == former)    cnt++;
            else {
                chars[start++] = former;
                if (cnt > 1) {
                    char[] ca = String.valueOf(cnt).toCharArray();
                    for(char digit : ca) {
                        chars[start++] = digit;
                    }
                }
                
                // Reset
                cnt = 1;
                former = c;
            }
        }
        
        // Add the last part of the array
        chars[start++] = former;
        if (cnt > 1) {
            char[] ca = String.valueOf(cnt).toCharArray();
            for(char digit : ca) {
                chars[start++] = digit;
            }
        }
        
        
        return start;
    }
}