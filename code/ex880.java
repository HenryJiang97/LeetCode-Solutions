class Solution {
    public String decodeAtIndex(String S, long K) {
        long cnt = 0;
        
        for (int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);
            
            if (Character.isLetter(c)) {    // Meets a letter
                cnt++;
                if (cnt == K)    return Character.toString(c);
                
            } else {
                int multiplies = c - '0';
                
                if (cnt * multiplies < K) {
                    cnt *= multiplies;
                } else {
                    if (K % cnt == 0) {
                        return decodeAtIndex(S.substring(0, i + 1), cnt);
                    } else {
                        return decodeAtIndex(S.substring(0, i + 1), K % cnt);
                    }
                }
            }
        }
        
        return "";
    }
}